/*
 * StringHashTable.h
 *
 */

#ifndef COMMANDS_STRINGHASHTABLE_H_
#define COMMANDS_STRINGHASHTABLE_H_

#include "Parameters.h"
#include "CommandCreator.h"

typedef bool (*fptr)(Parameters*);

class StringHashEntry{
public:
	StringHashEntry(){
		this->set = false;
		this->func = NULL;
	}
	StringHashEntry(String key,fptr func){
		this->key = key;
		this->func = func;
		this->set = true;
	}
	String getKey(){
		return key;
	}
	fptr getFptr(){
		return func;
	}
	void setFptr(fptr func){
		this->func = func;
	}
	boolean isSet(){
		return set;
	}

private:
	String key;
	fptr func;
	boolean set;

};

class StringHashTable{
public:
	StringHashTable(){
		for(int i=0;i<TABLE_SIZE;i++){
			table[i] = StringHashEntry();
		}
	}
	fptr get(String key){
		int hash;
		int len = key.length();
		char ch[len];
		int sum = 0;
		key.toCharArray(ch,len,0);
		for(int i=0;i<len;i++){
			sum+=ch[i];
		}
		hash = sum%TABLE_SIZE;
		while(table[hash].isSet()&&!table[hash].getKey().equals(key)){
			hash = (hash+1)%TABLE_SIZE;
		}
		if(!table[hash].isSet()){
			return NULL;
		}else{
			return table[hash].getFptr();
		}
	}
	void put(String key,fptr func){
		int hash;
		int len = key.length();
		char ch[len];
		int sum = 0;
		key.toCharArray(ch,len,0);
		for(int i=0;i<len;i++){
			sum+=ch[i];
		}
		hash = sum%TABLE_SIZE;
		while(table[hash].isSet()&&!table[hash].getKey().equals(key)){
			hash = (hash+1)%TABLE_SIZE;
		}
		table[hash] = StringHashEntry(key,func);
	}

private:
	const static int TABLE_SIZE = 24;
	StringHashEntry table[TABLE_SIZE];

};

#endif /* COMMANDS_STRINGHASHTABLE_H_ */
