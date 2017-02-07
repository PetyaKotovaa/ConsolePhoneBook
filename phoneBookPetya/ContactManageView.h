#pragma once
#include "Enumerator.h"
class ContactManageView
{
public:
	ContactManageView();
	~ContactManageView();

	CRUDMenuItems RenderMenu();

	void Create();
	void Read();
	void View();
	void Update();
	void Delete();
	void Run();
};

