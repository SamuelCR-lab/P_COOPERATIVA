#!/bin/bash

# Hacer git add .
git add .

# Solicitar mensaje de commit
echo "Introduce el mensaje para el commit: "
read mensaje_commit

# Hacer git commit con el mensaje proporcionado
git commit -m "$mensaje_commit"

# Hacer git push usando SSH (te pedirá la passphrase de tu clave SSH)
git push origin master
