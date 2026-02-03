// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:action/Count.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__ACTION__DETAIL__COUNT__BUILDER_HPP_
#define MY_INTERFACES__ACTION__DETAIL__COUNT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/action/detail/count__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_Goal_target
{
public:
  Init_Count_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::action::Count_Goal target(::my_interfaces::action::Count_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_Goal>()
{
  return my_interfaces::action::builder::Init_Count_Goal_target();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_Result_final_count
{
public:
  Init_Count_Result_final_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::action::Count_Result final_count(::my_interfaces::action::Count_Result::_final_count_type arg)
  {
    msg_.final_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_Result>()
{
  return my_interfaces::action::builder::Init_Count_Result_final_count();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_Feedback_current
{
public:
  Init_Count_Feedback_current()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::action::Count_Feedback current(::my_interfaces::action::Count_Feedback::_current_type arg)
  {
    msg_.current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_Feedback>()
{
  return my_interfaces::action::builder::Init_Count_Feedback_current();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_SendGoal_Request_goal
{
public:
  explicit Init_Count_SendGoal_Request_goal(::my_interfaces::action::Count_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_interfaces::action::Count_SendGoal_Request goal(::my_interfaces::action::Count_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_SendGoal_Request msg_;
};

class Init_Count_SendGoal_Request_goal_id
{
public:
  Init_Count_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Count_SendGoal_Request_goal goal_id(::my_interfaces::action::Count_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Count_SendGoal_Request_goal(msg_);
  }

private:
  ::my_interfaces::action::Count_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_SendGoal_Request>()
{
  return my_interfaces::action::builder::Init_Count_SendGoal_Request_goal_id();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_SendGoal_Response_stamp
{
public:
  explicit Init_Count_SendGoal_Response_stamp(::my_interfaces::action::Count_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_interfaces::action::Count_SendGoal_Response stamp(::my_interfaces::action::Count_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_SendGoal_Response msg_;
};

class Init_Count_SendGoal_Response_accepted
{
public:
  Init_Count_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Count_SendGoal_Response_stamp accepted(::my_interfaces::action::Count_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Count_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_interfaces::action::Count_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_SendGoal_Response>()
{
  return my_interfaces::action::builder::Init_Count_SendGoal_Response_accepted();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_GetResult_Request_goal_id
{
public:
  Init_Count_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_interfaces::action::Count_GetResult_Request goal_id(::my_interfaces::action::Count_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_GetResult_Request>()
{
  return my_interfaces::action::builder::Init_Count_GetResult_Request_goal_id();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_GetResult_Response_result
{
public:
  explicit Init_Count_GetResult_Response_result(::my_interfaces::action::Count_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_interfaces::action::Count_GetResult_Response result(::my_interfaces::action::Count_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_GetResult_Response msg_;
};

class Init_Count_GetResult_Response_status
{
public:
  Init_Count_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Count_GetResult_Response_result status(::my_interfaces::action::Count_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Count_GetResult_Response_result(msg_);
  }

private:
  ::my_interfaces::action::Count_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_GetResult_Response>()
{
  return my_interfaces::action::builder::Init_Count_GetResult_Response_status();
}

}  // namespace my_interfaces


namespace my_interfaces
{

namespace action
{

namespace builder
{

class Init_Count_FeedbackMessage_feedback
{
public:
  explicit Init_Count_FeedbackMessage_feedback(::my_interfaces::action::Count_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_interfaces::action::Count_FeedbackMessage feedback(::my_interfaces::action::Count_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::action::Count_FeedbackMessage msg_;
};

class Init_Count_FeedbackMessage_goal_id
{
public:
  Init_Count_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Count_FeedbackMessage_feedback goal_id(::my_interfaces::action::Count_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Count_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_interfaces::action::Count_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::action::Count_FeedbackMessage>()
{
  return my_interfaces::action::builder::Init_Count_FeedbackMessage_goal_id();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__ACTION__DETAIL__COUNT__BUILDER_HPP_
