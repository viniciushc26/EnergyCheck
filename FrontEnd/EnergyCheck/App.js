import React, { useEffect, useState } from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { StatusBar } from 'react-native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { Home } from './src/pages/home';
import { Configuracoes } from './src/pages/configuracoes';
import { Relatorios } from './src/pages/relatorios';
import { Perfil } from './src/pages/perfil';
import { Auth } from './src/pages/auth';
import Criarconta from './src/pages/criarconta';
import { RecuperarConta } from './src/pages/recuperarconta';
import AsyncStorage from '@react-native-async-storage/async-storage'; 
import { signInWithEmailAndPassword, getAuth } from 'firebase/auth'; 
import { auth } from './src/firebase.config'; 
import { useFonts, ChangaOne_400Regular, ChangaOne_400Regular_Italic } from '@expo-google-fonts/changa-one';
import { Kanit_400Regular, Kanit_500Medium, Kanit_600SemiBold } from '@expo-google-fonts/kanit';
import { useNavigation } from '@react-navigation/native';
import { Ionicons } from '@expo/vector-icons';

const Stack = createNativeStackNavigator();
const Tab = createBottomTabNavigator();

export function AuthStack() {
  return (
    <Stack.Navigator>
      <Stack.Screen
        name="auth"
        component={Auth}
        options={{ headerShown: false }}
      />
      <Stack.Screen
        name="criarconta"
        component={Criarconta}
        options={{ headerShown: false }}
      />
      <Stack.Screen
        name="recuperarconta"
        component={RecuperarConta}
        options={{ headerShown: false }}
      />
    </Stack.Navigator>
  );
}

export function MainTabNavigator() {
  return (
    <Tab.Navigator>
      <Tab.Screen
        name="home"
        component={Home}
        options={{
          tabBarShowLabel: false,
          headerShown: false,
          tabBarIcon: ({ focused, size, color }) => {
            return focused ? (
              <Ionicons size={size} color={color} name="home" />
            ) : (
              <Ionicons size={size} color={color} name="home-outline" />
            );
          },
        }}
      />
      <Tab.Screen
        name="relatorios"
        component={Relatorios}
        options={{
          tabBarShowLabel: false,
          headerShown: false,
          tabBarIcon: ({ focused, size, color }) => {
            return focused ? (
              <Ionicons size={size} color={color} name="bar-chart" />
            ) : (
              <Ionicons size={size} color={color} name="bar-chart-outline" />
            );
          },
        }}
      />
      <Tab.Screen
        name="configuracoes"
        component={Configuracoes}
        options={{
          tabBarShowLabel: false,
          headerShown: false,
          tabBarIcon: ({ focused, size, color }) => {
            return focused ? (
              <Ionicons size={size} color={color} name="cog" />
            ) : (
              <Ionicons size={size} color={color} name="cog-outline" />
            );
          },
        }}
      />
      <Tab.Screen
        name="perfil"
        component={Perfil}
        options={{
          tabBarShowLabel: false,
          headerShown: false,
          tabBarIcon: ({ focused, size, color }) => {
            return focused ? (
              <Ionicons size={size} color={color} name="person" />
            ) : (
              <Ionicons size={size} color={color} name="person-outline" />
            );
          },
        }}
      />
    </Tab.Navigator>
  );
}

export function useAuthNavigation() {
  const navigation = useNavigation();

  function navigateToAuth() {
    navigation.navigate('auth');
  }

  return { navigateToAuth };
}

export default function App() {
  const [isLogged, setIsLogged] = useState(false);

  useEffect(() => {
    const checkSavedCredentials = async () => {
      try {
        const userEmail = await AsyncStorage.getItem('userEmail');
        const userPassword = await AsyncStorage.getItem('userPassword');
        if (userEmail && userPassword) {
          const auth = getAuth();
          signInWithEmailAndPassword(auth, userEmail, userPassword)
            .then((userCredential) => {
              const user = userCredential.user;
              setIsLogged(true);
            })
            .catch((error) => {
              if (error.code === 'auth/missing-password') {
                // Usuário não tem uma senha configurada
                console.error('Usuário não tem uma senha configurada');
              } else {
                console.error(error);
              }
            });
        }
      } catch (error) {
        console.error(error);
      }
    };

    checkSavedCredentials();
  }, []);

  const [fontLoaded] = useFonts({
    ChangaOne_400Regular,
    ChangaOne_400Regular_Italic,
    Kanit_400Regular,
    Kanit_500Medium,
    Kanit_600SemiBold,

  });

  if(!fontLoaded){
    return null;
  }

  return (
    <NavigationContainer>
      <StatusBar backgroundColor="#000000" barStyle="light-content" />
      {isLogged ? <MainTabNavigator /> : <AuthStack />}
    </NavigationContainer>
  );
}
