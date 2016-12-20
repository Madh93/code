#! /bin/bash

#
## CONFIG
###

configrc="mycprc.txt"
# mycp_dir="mycp"


#
## GENERAL FUNCTIONS
###

get_directory() {
  # Directory
  if [ -d $1 ]; then
    directory=$(echo $1 | grep '^/')
    if [ -z $directory ]; then
      directory="$(pwd)/$(ls | grep $1)"
    fi
  # Device (/dev/sdX)
  elif [ -b $1 ]; then
    directory=$(mount | grep $1' ' | cut -d " " -f3)
    if [ -z $directory ]; then
      echo "Unknown device/not mounted: $1"
      exit 0
    fi
  else
    echo "Unknown path/does not exist: $1"
    exit 0
  fi
}

salir() {
  exit 0
}

# Select one
copy() {
  echo "Copying: $1"

  # 1: cp - copy files and directories
  cp $1 $2

  # 2: rsync - a fast, versatile, remote (and local) file-copying tool
  # rsync -a $1 $2

  # 3: pv - monitor the progress of data through a pipe
  # pv $1 > $2

  echo "Copied: $1"
  echo "---------------------------"
}


#
## MAIN
###

if [ "$#" -ne 2 ]; then
  echo "Bad number of arguments"
  exit 0
fi

# Get input and output directories
get_directory $1
input_dir=$directory
get_directory $2
output_dir=$directory

echo "*Copy: $input_dir/"
echo "*Destination: $output_dir/"

# Comprobar archivo de configuracion

# if [ ! -f "$output_dir/$configrc" ]; then
#   echo "No existe archivo de configuracion"
#   # Crear archivo vacio
#   # touch "$output_dir/$configrc"
# fi


del_path=$(dirname $input_dir/)

# Creating Directories
echo -e "\n*Creating directories:"

directories=$(find -L $input_dir -type d)
for d in $directories; do
  # mkdir -p "$output_dir${d#$del_path}"
  echo "Created: $output_dir${d#$del_path}"
done


# Copying files
echo -e "\n*Copying files:"

find -L $input_dir -type f -print0 | while IFS= read -r -d '' file; do
  # Check free space
  file_size=$(du -BK "$file" | cut -d "K" -f1)
  dest_size=$(df -k --output=avail $output_dir | tail -1)
  if [ $file_size -lt $dest_size ]; then
    # copy $f "$output_dir${f#$del_path}"
    echo "copiando"
  else
    echo "No free space at $output_dir"
    exit 0
  fi
done


echo -e "\n*Terminated: All files copied."


# Comprobar
# que pasa si ya existe un archivo
# que pasa si ya existe un archivo (pero esta incompleto)
# comprobar que hay suficiente espacio antes de copiar



# Eliminar linea de un archivo
# grep -vwE "(cat|rat)" sourcefile > destinationfile




# # MAIN
# case "$1" in 
#   -f | --force)
#     echo "forzar"
#     ;;
#   -h | --help)
#     echo "ayuda"
#     ;;
#   "")
#     echo "vacio"
#     ;;
#   *)
#     echo "ninguno"
#     ;;
# esac