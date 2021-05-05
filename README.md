# domotica-jaqueria
Proyecto domotizacion Jaqueria

**Esto es negrita**

**1. Crear imagen Docker Home Assistant**

Primero instale una maquina virtual ubuntu 20.04 con todas sus dependencias, instale docker y despues la imagen docker de home assistant

**2. Seleccion de licencia**

- Licencia de software:

    Eleji la licencia MIT, ya que es una licencia breve y permisiva con condiciones que requieren la preservacion de los avisos de licencia y derechos de autor

- Licencia de contenido:

    Eleji una licencia personalizada, permitiendo que se compartan las adaptaciones y  permitiendo los usos comerciales del proyecto

    <a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Licencia de Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />Este obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">licencia de Creative Commons Reconocimiento 4.0 Internacional</a>.

**3. Crear Bot Telegram**

Para ello, recurri a BotFather haciendo lo siguiente:

- Cree el nuevo bot ( /newbot )
    
    Asignandole un nombre y un nombre de usuario, dandome Telegram un token de autorizacion para emplear dicho bot

- Guarde el token en un lugar seguro

- Edite la descripcion del bot

- Edite la foto de perfil del bot

**Crear LDAP**

- Instale la imagen docker LDAP en Ubuntu
- Cree un docker-compose con LDAP y Home Assistant. En cuanto a sus cambios mas importantes son los siguientes:

    1. Indicar los 2 puertos que usara LDAP (1389,1636) e indicar el puerto que usara HomeAssistant (8123)
    2. Indicar parametros para el usuario administrador para LDAP
    3. Asignar el dominio de la Jaqueria 
    4. Asignar el directorio donde se almacenara LDAP y HomeAssistant

**Crear imagen de Docker con phpldapadmin**

- Instale la imagen docker en Ubuntu
- Añadi la configuracion de phpldapadmin al docker-compose con detalles importantes como:

    1. Host de phpldapadmin, que sera openldap
    2. Deshabilitar https
    3. Indicar el dominio de la Jaqueria
    4. Indicar el usuario administrador
    5. Indicar el puerto que usara phpldapadmin
    6. Indicar que depende del protocolo openldap

**Crear sensor de humedad y temperatura**

    Mediante ESPHOME, configurar un ESP32(medidor de temperatura) haciendo lo siguiente:

1. Instalar Python para usar "pip" e instalar ESPHOME(cmd)

    ```pip install esphome```

2. Configurar parametros iniciales como nombre del dispositivo, microcontrolador usado, modelo de placa, SSID de Wifi, y la contraseña de esta, en la que mediante este comando se crea el archivo .yml llamado temperatura

    ```python -m esphome temperatura.yml wizard```

3. En el archivo .yml creado, incorporar la configuracion que llevara el medidor de temperatura que sera la siguiente:

    - SSID del Wifi
    - Contraseña del Wifi
    - Contraseña de la API de HomeAssistant
    - PIN de la placa donde se conecta el sensor
    - Nombre que tendra el sensor de temperatura y      humedad
    - Intervalo de segundos donde la informacion del sensor se ira actualizando

4. Una vez configurado, ejecutamos el siguiente comando para que funcione el sensor

    ```python -m esphome temperatura.yml run```

5. Lo siguiente que hara sera pedirnos el puerto donde esta conectado el sensor, asi que ponemos el que corresponda a "COM3"

6. Por ultimo nos pedira la contraseña que configuramos en "temperatura.yml"

        Una vez hecho todo esto, en el HomeAssistant habra que ir al apartado de configuracion, integraciones y agregar una nueva integracion. Buscamos "ESPHOME" y saldra el dispositivo integrado con sus 2 entidades, en este caso temperatura y humedad.


**Configurar grupos y usuarios LDAP**

En este caso, se hara lo siguiente:

- Crear el grupo de administradores, con la informacion correspondiente y asignando los permisos adecuados
- Crear el grupo de socios, con la informacion de estos y con los permisos que les correspondan
- Todo esto se hace mediante el navegador web con phpldapadmin de la siguiente manera:

    1. Creamos la unidad organizativa administradores dando a jaqueria>create a child entry>organisational unit> y con el nombre "Administradores"

    2. Creamos la unidad organizativa sociosjaqueria dando a jaqueria>create a child entry>organisational unit> y con el nombre de "Socios Jaqueria"

    3. Creamos los usuarios Remedios, Pedro y Victor que seran los administradores dando a Administradores>create a child entry>default>InetOrgPerson. Una vez ahi, se selecciona el atributo en este caso "cn" y para cada uno de los 3 se rellanaran las casillas "cn", "sn" con el nombre, "password" con la contraseña y "username" con el nombre de usuario para entrar

    4. Al ser socios tambien estos 3 usuarios, se añadiran dando a la unidad organizativa Administradores>copy or move this entry>destination dn y elegimos "Socios Jaqueria". Tambien se marcara la casilla de borrar despues de su copia para que no se creen dos, si no que se borre la primera y se copie la unidad organizativa "Administradores" dentro de "Socios Jaqueria"

    5. Creamos todos los usuarios restantes, dando a SociosJaqueria>create a child entry>default>InetOrgPerson. Una vez ahi, se selecciona el atributo en este caso "cn" y para cada uno de socios se rellanaran las casillas "cn", "sn" con el nombre, "password" con la contraseña y "username" con el nombre de usuario para entrar

**Configurar Bot de Telegram en Home Assistant**

Para ello, habra que configurar el archivo "configuration.yaml" situado en la ruta que se definio en "docker-compose", en este caso "/home/administrador/config"

Los pasos de configuracion en "configuration.yaml" son los siguientes:

- Indicar el token del bot de telegram que usara HomeAssistant
- Indicar los "chatid" de mi usuario, y el grupo de la Jaqueria
- Indicar los "chatid" anteriores en otro apartado para habilitar las notificaciones

**Añadir imagen docker para Mosquitto**

- Instale la imagen docker Eclipse Mosquitto
- En el docker-compose, lo añadi con informacion como la siguiente:

    1. Indicar los 2 puertos que utilizara mosquitto
    2. Indicar el directorio donde se almacenara mosquitto
    3. Indicar en el apartado de homeassistant que depende de mosquitto(depends_on)

    
**Configurar broker MQTT para HomeAssistant**

Para ello iremos al "configuration.yaml" situado en la ruta "/home/admministrador/config" indicando lo siguiente:

- El broker, en este caso mosquitto
- El puerto por el que funcionara(9001)

Una vez hecho esto habra que hacer lo siguiente:

- Entrar en el docker de mosquitto, y crear un archivo llamado "passwd.txt" con el usuario jaqueria
- En la ruta donde tengamos mosquitto(mconfig), se añadira el archivo mosquitto.conf con las siguientes lineas:

    1. "allow_anonymous false" para que no se permita entrar a nadie anonimo
    2. "password_file /mosquitto/config/passwd.txt" para indicar el archivo que contendra el usuario jaqueria creado anteriormente


**Integrar Sensor CO2**

 Mediante ESPHOME, configurar un ESP32(medidor de temperatura) haciendo lo siguiente:

1. Instalar Python ya hecho anteriormente

2. Configurar parametros iniciales como nombre del dispositivo, microcontrolador usado, modelo de placa, SSID de Wifi, y la contraseña de esta, en la que mediante este comando se crea el archivo .yml llamado sensorco2

    ```python -m esphome sensorco2.yml wizard```

3. En el archivo .yml creado, incorporar la configuracion que llevara el medidor de temperatura que sera la siguiente:

    - SSID del Wifi
    - Contraseña del Wifi
    - Contraseña de la API de HomeAssistant
    - PIN de la placa donde se conecta el sensor
    - Nombre que tendra el sensor de CO2
    - Intervalo de segundos donde la informacion del sensor se ira actualizando

4. Una vez configurado, ejecutamos el siguiente comando para que funcione el sensor

    ```python -m esphome sensorco2.yml run```

5. Lo siguiente que hara sera pedirnos el puerto donde esta conectado el sensor, asi que ponemos el que corresponda a "COM3"

6. Por ultimo nos pedira la contraseña que configuramos en "sensorco2.yml"

        Una vez hecho todo esto, en el HomeAssistant habra que ir al apartado de configuracion, integraciones y agregar una nueva integracion. Buscamos "ESPHOME" y saldra el dispositivo integrado con sus 2 entidades, en este caso el sensor de co2 y otra nueva entidad que mide otros parametros

**Integrar telefono en desuso como camara webIP**

Se haran los siguientes pasos:

1. Se instalara la aplicacion "IP webcam" para que el movil solo funcione como camara y como una direccion IP,
2. Lo siguiente sera ir al "configuration.yaml" para incorporar la nueva camara es este caso especificando lo siguiente:

    - Direccion IP del dispositivo movil
    - Puerto, en este caso el predeterminado (8080)
    - Usuario y contraseña que se configura en la aplicacion  "IP webcam"

**Integrar ESP32CAM**

 Mediante ESPHOME, configurar un ESP32cam haciendo lo siguiente:

1. Instalar Python ya hecho anteriormente

2. Configurar parametros iniciales como nombre del dispositivo, microcontrolador usado, modelo de placa, SSID de Wifi, y la contraseña de esta, en la que mediante este comando se crea el archivo .yml llamado camara1

    ```python -m esphome camara1.yml wizard```

3. En el archivo .yml creado, incorporar la configuracion que llevara el medidor de temperatura que sera la siguiente:

    - SSID del Wifi
    - Contraseña del Wifi
    - Contraseña de la API de HomeAssistant
    - PIN de la placa donde se conecta el sensor
    - Nombre que tendra el sensor de CO2
    - Resolucion de la camara
    - Calidad jpeg de las fotos
    - Todos los pins que se conectan al microprocesador

4. Una vez configurado, ejecutamos el siguiente comando para que funcione el sensor

    ```python -m esphome camara1.yml run```

5. Lo siguiente que hara sera pedirnos el puerto donde esta conectado el sensor, asi que ponemos el que corresponda a "COM3"

6. Por ultimo nos pedira la contraseña que configuramos en "camara1.yml"

        Una vez hecho todo esto, en el HomeAssistant habra que ir al apartado de configuracion, integraciones y agregar una nueva integracion. Buscamos "ESPHOME" y saldra el dispositivo integrado con sus 2 entidades, en este caso el sensor de co2 y otra nueva entidad que mide otros parametros

**Crear imagen para ZIgbee2MQTT**

- Instale la imagen docker Zigbee2MQTT
- En el docker-compose, lo añadi con informacion como la siguiente:

    1. El nombre del dispositivo del USB conectado
    2. La zona horaria
    3. La ruta donde se almacenara la configuracion de Zigbee


**Conectar Zigbee2MQTT a HomeAssistant**

Lo que se trata de hacer es conectar Zigbee2MQTT a mosquitto, para que desde la regleta inalambrica se pueda mandar informacion con mosquitto a HomeAssistant

Para ello vamos a la ruta de zigbee especificada en el paso anterior en este caso "/home/administrador/data" y editamos el archivo "configuration.yaml" con lo siguiente:

- Especificar el servidor, en este caso ponemos el docker de mosquitto y su puerto
- Especificar el usuario y contraseña que configuramos en mosquitto

**Crear automatizaciones en el local**

Regla 1º: Automatizacion del sensor de CO2 cuando alcanza mas de 620 particulas por minuto.

Dentro de HomeAssistant, iremos a Configuracion>Automatizaciones>signo + para añadir una nueva automatizacion

- Elegimos un nombre para la automatizacion.
- Asignamos un desencadenante de tipo dispositivo con valor maximo 620
- Configuramos una accion de tipo llamada, con un nombre y con el siguiente mensaje "las ppm han llegado a su maximo"

Regla 2º: A partir de las 21:00, se encienda la luz del sensor de la camara.

Dentro de HomeAssistant, iremos a Configuracion>Automatizaciones>signo + para añadir una nueva automatizacion

- Elegimos un nombre para la automatizacion
- Asignamos un desencadenante de tipo hora con el valor de las 21:00 horas
- Configuramos una accion de tipo llamada, con el servicio "Interruptor: turn on" y elegimos la entidad, en este caso la camara

Regla 3º: A partir de las 7:00, se apagara la luz del sensor de la camara.
 
Dentro de HomeAssistant, iremos a Configuracion>Automatizaciones>signo + para añadir una nueva automatizacion

- Elegimos un nombre para la automatizacion
- Asignamos un desencadenantes de tipo hora con el valor de las 7:00 horas
- Configuramos una accion de tipo llamada, con el servicio "Interruptor: turn off" y elegimos la entidad, en este caso la camara

Regla 4º: Cuando llegue la temperatura a mas de 25 grados, se debera encender el enchufe numero 2 de la regleta zigbee

Dentro de HomeAssistant, iremos a Configuracion>Automatizaciones>signo + para añadir una nueva automatizacion

- Elegimos un nombre para la automatizacion
- Asignamos un desencadenantes de tipo dispositivo con el valor maximo de 25
- Configuramos una accion de tipo llamada, con el servicio "Interruptor: turn on" y elegimos la entidad, en este caso el enchufe numero 2 de la regleta


Regla 5ª Cuando la temperatura baje de 22 grados, se debera apagar el enchufe numero 2 de la regleta zigbee

Dentro de HomeAssistant, iremos a Configuracion>Automatizaciones>signo + para añadir una nueva automatizacion

- Elegimos un nombre para la automatizacion
- Asignamos un desencadenantes de tipo dispositivo con el valor minimo de 22
- Configuramos una accion de tipo llamada, con el servicio "Interruptor: turn off" y elegimos la entidad, en este caso el enchufe numero 2 de la regleta

**Acceso por NFC**

Mediante ESPHOME, configurar un lector NFC haciendo lo siguiente:

1. Instalar Python ya hecho anteriormente

2. Configurar parametros iniciales como nombre del dispositivo, microcontrolador usado, modelo de placa, SSID de Wifi, y la contraseña de esta, en la que mediante este comando se crea el archivo .yml llamado camara1

    ```python -m esphome lectornfc.yml wizard```

3. En el archivo .yml creado, incorporar la configuracion que llevara el medidor de temperatura que sera la siguiente:

    - SSID del Wifi
    - Contraseña del Wifi
    - Contraseña de la API de HomeAssistant
    - Pin CSO
    - Pin CLK
    - Pin MOSI
    - Pin MISO

4. Una vez configurado, ejecutamos el siguiente comando para que funcione el sensor

    ```python -m esphome lectornfc.yml run```

5. Lo siguiente que hara sera pedirnos el puerto donde esta conectado el sensor, asi que ponemos el que corresponda a "COM3"

6. Por ultimo nos pedira la contraseña que configuramos en "camara1.yml"

        Una vez hecho todo esto, en el HomeAssistant habra que ir al apartado de configuracion, integraciones y agregar una nueva integracion. Buscamos "ESPHOME" y saldra el dispositivo integrado con su entidaded, en este caso el sensor RFID

