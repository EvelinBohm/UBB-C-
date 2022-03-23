#pragma once
#include"Car.h"
#include <vector>
template<class E>
class CrudRepos
{
	
public:
	virtual bool delete_entity(E entity) =0;
	virtual bool update_entity(E entity_to_update, E updated_entity)=0;
	virtual bool add_entity(E entity) =0;
	virtual ~CrudRepos() {};


};