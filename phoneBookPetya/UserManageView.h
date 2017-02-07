#pragma once
#include "Enumerator.h"
class UserManageView
{
public:
	UserManageView();
	~UserManageView();

	CRUDMenuItems RenderMenu();
	void Create();
	void Read();
	void Update();
	void Delete();

	void Run();


};

