// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:action/Count.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__ACTION__DETAIL__COUNT__STRUCT_H_
#define MY_INTERFACES__ACTION__DETAIL__COUNT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_Goal
{
  int32_t target;
} my_interfaces__action__Count_Goal;

// Struct for a sequence of my_interfaces__action__Count_Goal.
typedef struct my_interfaces__action__Count_Goal__Sequence
{
  my_interfaces__action__Count_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_Result
{
  int32_t final_count;
} my_interfaces__action__Count_Result;

// Struct for a sequence of my_interfaces__action__Count_Result.
typedef struct my_interfaces__action__Count_Result__Sequence
{
  my_interfaces__action__Count_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_Feedback
{
  int32_t current;
} my_interfaces__action__Count_Feedback;

// Struct for a sequence of my_interfaces__action__Count_Feedback.
typedef struct my_interfaces__action__Count_Feedback__Sequence
{
  my_interfaces__action__Count_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "my_interfaces/action/detail/count__struct.h"

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_interfaces__action__Count_Goal goal;
} my_interfaces__action__Count_SendGoal_Request;

// Struct for a sequence of my_interfaces__action__Count_SendGoal_Request.
typedef struct my_interfaces__action__Count_SendGoal_Request__Sequence
{
  my_interfaces__action__Count_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} my_interfaces__action__Count_SendGoal_Response;

// Struct for a sequence of my_interfaces__action__Count_SendGoal_Response.
typedef struct my_interfaces__action__Count_SendGoal_Response__Sequence
{
  my_interfaces__action__Count_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} my_interfaces__action__Count_GetResult_Request;

// Struct for a sequence of my_interfaces__action__Count_GetResult_Request.
typedef struct my_interfaces__action__Count_GetResult_Request__Sequence
{
  my_interfaces__action__Count_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "my_interfaces/action/detail/count__struct.h"

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_GetResult_Response
{
  int8_t status;
  my_interfaces__action__Count_Result result;
} my_interfaces__action__Count_GetResult_Response;

// Struct for a sequence of my_interfaces__action__Count_GetResult_Response.
typedef struct my_interfaces__action__Count_GetResult_Response__Sequence
{
  my_interfaces__action__Count_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "my_interfaces/action/detail/count__struct.h"

/// Struct defined in action/Count in the package my_interfaces.
typedef struct my_interfaces__action__Count_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_interfaces__action__Count_Feedback feedback;
} my_interfaces__action__Count_FeedbackMessage;

// Struct for a sequence of my_interfaces__action__Count_FeedbackMessage.
typedef struct my_interfaces__action__Count_FeedbackMessage__Sequence
{
  my_interfaces__action__Count_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__action__Count_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__ACTION__DETAIL__COUNT__STRUCT_H_
