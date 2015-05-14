#1 Crear una nueva aplicacion:

	rails new nombre_aplicacion

#2 Correr aplicacion en el servidor local:

	rails server (dentro del directorio de la aplicacion)

#3 Crear un controlador (y automaticamente su vista)

	rails generate controller nombre_controlador nombre_archivo

#4 ¿Cambiar pagina de inicio? 
#El controlador tiene una vista (app/views/nombre/index.html.erb) que sera lo que mostrara como index
#Es necesario modificar la ruta de inicio (config/routes.rb) y añadir:

	root 'nombre_controlador#index'

#5 SCAFFOLDING: permite automatizar la creacion de un aplicacion 2.0
#Se necesita de formularios, scripts y bases de datos
#RoR utliza CRUD (Create-Read-Update-Delete)
#Seria necesario 4 formularios (uno para crear, otro para leer...), 4 scritps y 1 base de datos
#Se puede crear automaticamente todo estos archivos con scaffold

#Ejemplo de un blog: Existen los posts, los cuales necesitan de informacion como nombre,titulo,contenido

	rails generate scaffold Post nombre:string titulo:string contenido:text

#6 Instalar base de datos
#Se creo una base de datos con scaffold pero no se importo en la aplicacion Create-Read-Update-Delete

	rake db:migrate

#7 Utilizar mi controlador posts
# Vamos al index (app/views/nombre/index.html.erb) y añadimos lo siguiente:

	<%= link_to "Mi blog", posts_path %>


#8 Instalar gemas del proyecto rails
# Instalara automaticamente todas las gemas descritas en el archivo Gemfile

	bundle

#9 Mostrar un path de todo

	rake routes
