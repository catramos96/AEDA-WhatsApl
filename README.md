# Comandos do git #

## 1- Clonar o repositório para o vosso computador: ##

* Abrir terminal no source tree

* Fazer cd para a pasta onde querem o repositório

* git clone https://ines_gomes@bitbucket.org/ines_gomes/ines_gomes-aeda_whatsapl.git

## 2- Para fazer commits: ##

### Sempre que se abre o terminal é preciso fazer login ###

* git config --global user.name "Vosso nome"

* git config --global user.email "Vosso email da conta do bb"

### Para fazer commits estes passos têm de ser seguidos. Todos e por esta ordem para evitar problemas ###

* git add -A    //Adiciona todos os ficheiros novos ou alterados ao commit

* git commit -a -m "Mensagem do commit"

* git pull      //Ir buscar qualquer atualização ao rep antes de fazer upload das 
vossas adições de código

* git push     //Faz upload do commit para o repositório


## Outros comandos ##

* git status   //diz se o vosso rep está atualizado com o do site