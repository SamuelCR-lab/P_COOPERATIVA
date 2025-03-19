#!/bin/bash

# Hacer git add .
git add .

# Solicitar mensaje de commit
echo "Introduce el mensaje para el commit: "
read mensaje_commit

# Hacer git commit con el mensaje proporcionado
git commit -m "$mensaje_commit"

# Hacer git push (con usuario y token de acceso personal)
echo "Introduce tu usuario de Git: "
read usuario
echo "Introduce tu token de acceso personal (no tu contraseña): "
read -s token

# Empujar cambios al repositorio
git push https://$usuario:$token@github.com/D3LucasX/Dam.git
