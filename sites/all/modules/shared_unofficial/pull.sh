#!/bin/bash
projects=( "crl_access_by_ip" "crl_user_feat" "crl_inst_feat" "crowd_push" "crowd_batch_pull" )
for project in ${projects[@]}
do
    cd ${project}
    echo  
    echo Checking ${project}
    git fetch
    git status
    read -p "Run pull for ${project}? " -n 1 -r
    echo    
    if [[ $REPLY =~ ^[Yy]$ ]]
    then
        git pull
    fi
    cd ..
done
