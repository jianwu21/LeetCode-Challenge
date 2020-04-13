//
// Created by Jian Wu on 12/04/2020.
//

#include "StackSolution.h"


bool StackSolution::isValidSerialization(string preorder)
{
	int slots = 1;
	string token = "";

	for (auto it = preorder.begin(); it <= preorder.end(); ++it)
	{
		if (*it == ',' || it == preorder.end())
		{
			slots--;

			if (slots < 0)
				return false;

			if (token != "#") slots += 2;

			token = "";
			continue;
		}

		token += (*it);
	}

	return slots == 0;
}
