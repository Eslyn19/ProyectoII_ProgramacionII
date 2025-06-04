📚 **Simulacion de ecosistema**
---
✨ _Funcionalidad General_
---

  El proyecto consiste en crear criaturas aleatoriamente dependiendo de su alimentacion donde estas buscaran la supervivencia mediante el clima y los recursos. El ecosistema se base en herbivoros
  carnivoros y omnivoros donde estos pueden llegar a morir, reproducirse, moverse y alimentarse.

🚩 _Características Principales_
---

  ⚫ Aplicacion ejecutable.
  
  ⚫ Creado mediante patrones de diseño de C++.
  
  ⚫ Implementacion gráfica Raylib.
  
  ⚫ Cambio de clima mediante interfaz.

🧱 _Estructura del Proyecto_
---

  ► Patrones de diseño

  ⚫ Singleton: Controlador unico del entorno.

  ⚫ AbstractFactory: Creador abstracto de recuros & criaturas.

  ⚫ Observer: interacción al entorno.

  ⚫ Strategy: Implementación en los comportamientos de criaturas.

   ► Seres del entorno

   ⚫ Criatura: Herviboro, omnivoros y carnivoros.
   
   ⚫ Recursos: Agua, plantas, comida.

🛠️ _Requisitos del Sistema_
---    
    💻 Compilador C++ compatible con el estándar C++11 o superior.
  
    🧠 IDE recomendado: Visual Studio, CLion, Code::Blocks o similar.
  
    📦 Dependencias gestionadas con vcpkg.

📥 **Instalación de raylib con vcpkg & GitBash**

    $ git clone https://github.com/microsoft/vcpkg.git

    $ cd vcpkg

    $ ./bootstrap-vcpkg.bat

    $ cd ..

    $ ./vcpkg/vcpkg install raylib

    $ ./vcpkg integrate install


🚀 **Compilación y Ejecución**
    
    📁 Abrir el proyecto en tu IDE.

    ⚙️ Compilar la solución.

    ▶️ Ejecutar el programa.

🧑‍💻 **Autor**
---

Eslyn Andrés Jara Calderón

Universidad Nacional de Costa Rica

---
