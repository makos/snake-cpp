#include "Event/MenuEventArgs.hpp"

MenuEventArgs::MenuEventArgs(const char *tText, Event tEvent,
                             Observer *tObserver)
    : text(tText), event(tEvent), observer(tObserver) {}