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

**Crear sensor de humedad y temperatura

    Mediante ESPHOME, configurar un ESP32(medidor de temperatura) haciendo lo siguiente:

1. Instalar Python para usar "pip" e instalar ESPHOME(cmd)

```pip install esphome```

2. Configurar parametros iniciales como nombre del dispositivo, microcontrolador usado, modelo de placa, SSID de Wifi, y la contraseña de esta, creando un archivo .yml llamado temperatura

```python -m esphome temperatura.yml wizard```

3. En el archivo .yml creado, incorporar la configuracion que llevara el medidor de temperatura que sera la siguiente:

    - 
    

**Integrar LDAP como proveedor de identidades de Home Assistant

