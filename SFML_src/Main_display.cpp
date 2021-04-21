/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** main_display
*/

#include "Main_display.hpp"
#include "Top/Top_display.cpp"
#include "Left/Left_display.cpp"
#include "Mid/Mid_display.cpp"
#include "Right/Right_display.cpp"

void background_display(Basic *window)
{
    window->_window.draw(window->_backgroundS);
}

void main_display(block *container)
{
    background_display(container->window);
    if (container->window->_top == true) {
        container->window->_topT.setString("X");
        top_display(container->window, container->top, container->_user);
    } else
        container->window->_topT.setString("+");
    if (container->window->_mid == true) {
        container->window->_midT.setString("X");
        mid_display(container->window, container->mid, container->_mem);
    } else
        container->window->_midT.setString("+");
    if (container->window->_left == true) {
        container->window->_leftT.setString("X");
        left_display(container->window, container->left, container->_cpu);
    } else
        container->window->_leftT.setString("+");
        if (container->window->_right == true) {
        container->window->_rightT.setString("X");
        right_display(container->window, container->right, container->_net);
    } else
        container->window->_rightT.setString("+");
    container->window->_window.draw(container->window->_midT);
    container->window->_window.draw(container->window->_topT);
    container->window->_window.draw(container->window->_leftT);
    container->window->_window.draw(container->window->_rightT);
}
