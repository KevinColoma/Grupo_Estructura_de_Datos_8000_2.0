#include <iostream>
#include "application.h"
int main()
{
    std::setlocale(LC_ALL, ".UTF-8");
    return Application::run(ApplicationState::RUN);
}