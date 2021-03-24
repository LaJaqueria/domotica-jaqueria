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
- Cree un docker-compose con LDAP y Home Assistant