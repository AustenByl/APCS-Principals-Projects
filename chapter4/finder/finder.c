/**********************************
 * finder.c
 * 
 * CS50 AP
 * Finder
 * 
 * Searches for a target string in
 * all files in a directory
 * 
 * Name: Austen van der Byl
 * 
 **********************************/

#define _BSD_SOURCE
#define _GNU_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// struct to hold the file name and type
typedef struct 
{
    string name;
    string type;
} 
path;

// struct to hold the directory info
typedef struct 
{
    string name;
    int npaths;
    path* paths;
} 
directory;

// string to hold the word to seek
string key;

// the function to search for files in a directory and populate the struct
directory populate(directory dir);

// the function to recursively iterate through directories and handle files
int seek(directory dir);

// main - sets arguments and calls the seek function
int main(int argc, char* argv[])
{
    // Checks for the correct number of arguments
    if (argc < 2 || argc > 3)
    {
        printf("Ussage: ./finder word search_directory/");
        return false;
    }
    // If enough arguments, key is assigned
    else
    {
        key = argv[1];
    }
    // create initial directory
    directory dir;
    // If a directory is provided, assign its name
    if (argc == 3)
    {
        dir.name = argv[2];
    }
    // Otherwise the name is ./
    else
    {
        dir.name = "./";
    }
    
    // call the seek function
    return seek(dir);
}

// for a given directory, searches for files and fills array in the struct
directory populate(directory dir)
{
    // initialize all pointers and values in the given struct
    dir.npaths = 0;
    dir.paths = NULL;
    DIR* dirp;
    struct dirent* entry;
    
    // opendir is a system call that opens a "directory stream" containing
    // information about all files in the given directory (represented here 
    // by dir.name)
    dirp = opendir(dir.name);
    if (dirp == NULL) 
    {
        printf("Opening directory failed. Check your input filepath!\n");
        return dir;
    }
    
    // while directory stream still contains files, seek through them
    while((entry = readdir(dirp)) != NULL) 
    {
        // if entry is a directory and not '.' or '..',
        // increase file count and populate the struct
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) 
        {
            // allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 2);
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            strcat(name, "/");
            
            // reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));
            
            // add a new element to the array containing names and types
            path newPath = {.name = name, .type = "directory"};
            dir.paths[dir.npaths] = newPath;
            
            // increase file count for the directory
            dir.npaths++;
        }
        
        // else if entry is a file, increase file count and populate the struct
        else if (entry->d_type == DT_REG) 
        {
            // allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 1);
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            
            // reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));
            
            // add a new element to the array containing names and types
            path newPath = {.name = name, .type = "file"};
            dir.paths[dir.npaths] = newPath;
            
            // increase file count for the directory
            dir.npaths++;
        }
    }
    
    // close directory stream using system call closedir and return struct
    closedir(dirp);
    return dir;
    
}

// recursive function to iterate through directories and search files
int seek(directory dir)
{
    // Populates the directory being searched
    dir = populate(dir);
    // Itterates over every file in that directory then moves on the folders
    for(int i = 0; i < dir.npaths; i++)
    {
        // Checks current file
        if (strcmp(dir.paths[i].type, "file") == 0)
        {
            string currentFile = dir.paths[i].name;
            FILE* openFile = fopen(currentFile, "r");
            // Checks for key
            string answer = strstr(currentFile, key);
            // If key is found
            if (answer != NULL)
            {
                // Opens found file
                FILE* foundFile = fopen("found.txt", "a");
                // Appends name of file key was found in
                fputs(currentFile, foundFile);
                fputs("\n", foundFile);
                // Closes found file
                fclose(foundFile);
            }
            fclose(openFile);
        }
        // Calls seek if only directorys are left
        else
        {
            // Creates new directory
            directory dir2;
            // Sets the name to the name of 1st directory
            dir2.name = dir.paths[i].name;
            // Calls seek on "new" directory
            seek(dir2);
        }
    }
    return 0;
}
