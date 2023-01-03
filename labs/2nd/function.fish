function sort_files 

    set fileType $argv[1]
    set fileFirstCharacter $argv[2]

    mkdir -p $fileFirstCharacter/bytes $fileFirstCharacter/kilobytes $fileFirstCharacter/megabytes $fileFirstCharacter/gigabytes

    for i in (find ./ -name "$fileFirstCharacter*" -a -name "*.$fileType")
        wc -c $i > temp
        read filesize word < temp
        if [ $filesize -lt 1024 ]
            cp $i $fileFirstCharacter/bytes
        else if [ $filesize -lt 1048576 ]
            cp $i $fileFirstCharacter/kilobytes
        else if [ $filesize -lt 1073741824 ]
            cp $i $fileFirstCharacter/megabytes
        else
            cp $i $fileFirstCharacter/gigabytes
        end
        rm temp
    
    end
end #function