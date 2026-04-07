# CLIp Assistant

Esta sera la guia y Roadmap que seguira este proyecto. Sientanse libres de subir *issues* y *Pull Requests*. Ademas todo lo que se cambie sera escrito en ingles desde el codigo hasta la documentacion, eso incluye este archivo CONTRIBUTION.md, README.md y CHANGELOG.md. 

Este proyecto nacio basado en C++, Entonces, por que migrar a Rust si funciona en C++ y es estable?
> Rust es un lenguaje que tiene como **utilidad** principal el manejo **SEGURO** de la memoria sin sacrificar el rendimiento. Ademas Rust posee un gestor de paquetes mas centralizado con **Cargo** y **rustup**, evitando usar herramientas externas al lenguajue como CMake o relacionados.


***lo que se busca con las contribuciones es:***

- Refactorizar todo a Rust.
- Portear para Cross-Platform (funcione igual en windows, linux o mac).
- Estructura para Contenedores (Docker).
- Usar el compilador de Rust y Cargo para la gestion de librerias.


### ROADMAP

- ***Phase 1: Bases y Entorno:***

[ ] Saludo: Reimplementar el comando Hello y el sistema de bienvenida aleatoria.

[ ] Command Parser: Crear un motor simple que reciba texto del usuario y decida qué función ejecutar (usando el match de Rust).

[ ] Fecha y Hora: Implementar ShowHour usando el crate chrono para manejar zonas horarias de forma multiplataforma.


### Como contribuir

- Clona el repositorio 
> ```git clone https://github.com/Tasesho/clip_cloudshare```

- Crear una nueva Branch, antes de hacer cualquier cambio asegurate de **NO** trabajar en ```main```
>  ```git chekout -b cambio/nombre-del-cambio```

- Haz tus cambios

- Commit & Push, guarda tus cambios con mensajes descriptivos en **INGLES**

> ```git add .```

> ```git commit -m "update"```

> ```git push origin cambio/nombre-del-cambio```


- Abrir un Pull Request (PR), ve a la pagina del repositorio en github y veras un boton verde que dice "Compare & pull request". Describe que cambiaste y espera a que el owner apruebe o rechaze tus cambios.

## GUIDELINES

- English only: All code comments, commit messages, and documentation must be in English.

- Keep it simple: Since we are learning, try to write clean and readable code.

- Ask for help: If the Borrow Checker is giving you a hard time, open an Issue or ask in our communication channel.