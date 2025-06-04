📚 **Simulacion de ecosistema**
---
✨ _Funcionalidad General_
---

 El proyecto consiste en desarrollar una simulación de ecosistema donde criaturas con distintos tipos de alimentación (herbívoros, carnívoros y omnívoros) buscan sobrevivir mediante acciones como moverse, alimentarse, reproducirse y adaptarse al entorno. Las criaturas se generan aleatoriamente y su comportamiento depende de factores como el clima, la disponibilidad de recursos y su nivel de energía. El ecosistema evoluciona dinámicamente: los seres vivos pueden morir por hambre, edad o condiciones adversas, mientras que el clima y los recursos influyen constantemente en su supervivencia. La simulación se representa visualmente, permitiendo observar la interacción entre las criaturas y su entorno en tiempo real.

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
