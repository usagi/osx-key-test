#include <thread>
#include <chrono>
#include <iostream>

#include "/System/Library/Frameworks/CoreGraphics.framework/Versions/A/Headers/CGEvent.h"
#include "/System/Library/Frameworks/CoreGraphics.framework/Versions/A/Headers/CGEventSource.h"
#include "/System/Library/Frameworks/CoreGraphics.framework/Versions/A/Headers/CGEventTypes.h"
#include "/System/Library/Frameworks/CoreGraphics.framework/Versions/A/Headers/CGRemoteOperation.h"

int main()
{
  constexpr auto key_press_code   = true;
  constexpr auto key_release_code = false;
  
  constexpr auto keycode = CGKeyCode(38);
  
  auto event_source = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
  
  auto key_press_event   = CGEventCreateKeyboardEvent(event_source, keycode, key_press_code);
  auto key_release_event = CGEventCreateKeyboardEvent(event_source, keycode, key_release_code);
  
  //CGEventSetFlags(key_press_event, kCGEventFlagMaskShift);
  //CGEventSetFlags(key_release_event, kCGEventFlagMaskShift);
  
  for(auto n : {5,4,3,2,1})
  {
    std::cout << "count down: " << n << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  
  constexpr auto event_tap_location = kCGHIDEventTap;
  
  CGEventPost(event_tap_location, key_press_event);
  CGEventPost(event_tap_location, key_release_event);
  
  CFRelease(key_press_event);
  CFRelease(key_release_event);
}
