begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stdbool.h for GNU.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDBOOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__STDBOOL_H__
value|1
end_define

begin_comment
comment|/* The type `bool' must promote to `int' or `unsigned int'.  The constants    `true' and `false' must have the value 0 and 1 respectively.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_comment
comment|/* The names `true' and `false' must also be made available as macros.  */
end_comment

begin_define
define|#
directive|define
name|false
value|false
end_define

begin_define
define|#
directive|define
name|true
value|true
end_define

begin_comment
comment|/* Signal that all the definitions are present.  */
end_comment

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stdbool.h */
end_comment

end_unit

