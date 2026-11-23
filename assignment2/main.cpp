/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Ding Huan"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> all_names;
  std::ifstream file(filename);
  if(file.is_open())
  {
    std::string line;
    while(std::getline(file,line))
    {
      all_names.insert(line);
    }
  }

  return all_names;

}

std::string get_initials(std::string name)
{
  std::string name_init;
  size_t pos = name.find_first_of(' ');

  name_init.push_back(name[0]);
  name_init.push_back(name[pos+1]);
  //name_init = name[0] + name[pos+1];

  return name_init;

}



/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::string my_name;
  my_name = get_initials(name);
  std::queue<const std::string*> match_name;

  for(auto & a_name : students)
  {
    if(my_name == get_initials(a_name))
    {
      match_name.push(&(a_name));
    }
  }

  return match_name;

}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> copy = matches;
  std::string one;
  while(!copy.empty())
  {
    const std::string *  name = copy.front();

    if((*name).length() == kYourName.length())
    {
      one = *name;
    }

    copy.pop();

  }

  if(one.length() == 0)
  {
     one = "NO MATCHES FOUND.";
  }
  
  return one;

}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
