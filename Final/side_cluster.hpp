/****************************************************************
* File name:   side_cluster.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Side_Cluster class. It's the
* fourth zone of the game. It's also derived from the Space class.
*****************************************************************/

#include "space.hpp"

#ifndef SIDE_CLUSTER_H
#define SIDE_CLUSTER_H

class Side_Cluster : public Space
{
public:
	Side_Cluster(Player*);
	~Side_Cluster();
	virtual void set_map(char**);
	virtual void radar_text();
};
#endif

