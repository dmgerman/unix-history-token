begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Test header file for h2ph  *   * Try to test as many constructs as possible  * For example, the multi-line comment :)  */
end_comment

begin_comment
comment|/* And here's a single line comment :) */
end_comment

begin_comment
comment|/* Test #define with no indenting, over multiple lines */
end_comment

begin_define
define|#
directive|define
name|SQUARE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)*(x))
end_define

begin_comment
comment|/* Test #ifndef and parameter interpretation*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ERROR
end_ifndef

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|x
parameter_list|)
value|fprintf(stderr, "%s\n", x[2][3][0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H2PH_H_
end_ifndef

begin_define
define|#
directive|define
name|_H2PH_H_
end_define

begin_comment
comment|/* #ident - doesn't really do anything, but I think it always gets included anyway */
end_comment

begin_empty
empty|#ident "$Revision h2ph.h,v 1.0 98/05/04 20:42:14 billy $"
end_empty

begin_comment
comment|/* Test #undef */
end_comment

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_comment
comment|/* Test #ifdef */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SOME_UNIMPORTANT_PROPERTY
end_ifdef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SOME_UNIMPORTANT_PROPERTY */
end_comment

begin_comment
comment|/*   * Test #if, #elif, #else, #endif, #warn and #error, and `!'  * Also test whitespace between the `#' and the command  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
name|__SOMETHING_MORE_IMPORTANT
operator|)
end_if

begin_empty
empty|#    warn Be careful...
end_empty

begin_elif
elif|#
directive|elif
operator|!
operator|(
name|defined
name|__SOMETHING_REALLY_REALLY_IMPORTANT
operator|)
end_elif

begin_error
error|#
directive|error
error|Nup, can't go on /* '
end_error

begin_comment
comment|/* stupid font-lock-mode */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined __SOMETHING_MORE_IMPORTANT&& defined __SOMETHING_REALLY_REALLY_IMPORTANT */
end_comment

begin_define
define|#
directive|define
name|EVERYTHING_IS_OK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test&& and || */
end_comment

begin_undef
undef|#
directive|undef
name|WHATEVER
end_undef

begin_if
if|#
directive|if
operator|(
operator|!
operator|(
operator|(
name|defined
name|__SOMETHING_TRIVIAL
operator|&&
name|defined
name|__SOMETHING_LESS_SO
operator|)
operator|)
expr|\
operator|||
name|defined
name|__SOMETHING_OVERPOWERING
operator|)
end_if

begin_define
define|#
directive|define
name|WHATEVER
value|6
end_define

begin_elif
elif|#
directive|elif
operator|!
operator|(
name|defined
name|__SOMETHING_TRIVIAL
operator|)
end_elif

begin_comment
comment|/* defined __SOMETHING_LESS_SO */
end_comment

begin_define
define|#
directive|define
name|WHATEVER
value|7
end_define

begin_elif
elif|#
directive|elif
operator|!
operator|(
name|defined
name|__SOMETHING_LESS_SO
operator|)
end_elif

begin_comment
comment|/* defined __SOMETHING_TRIVIAL */
end_comment

begin_define
define|#
directive|define
name|WHATEVER
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined __SOMETHING_TRIVIAL&& defined __SOMETHING_LESS_SO */
end_comment

begin_define
define|#
directive|define
name|WHATEVER
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Test #include, #import and #include_next  * #include_next is difficult to test, it really depends on the actual  *  circumstances - for example, `#include_next<limits.h>' on a Linux system  *  with `use lib qw(/opt/perl5/lib/site_perl/i586-linux/linux);' or whatever  *  your equivalent is...  */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_empty
empty|#import "sys/ioctl.h"
end_empty

begin_empty
empty|#include_next<sys/fcntl.h>
end_empty

begin_comment
comment|/* typedefs should be ignored */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|a_struct
block|{
name|int
name|typedefs_should
decl_stmt|;
name|char
name|be_ignored
decl_stmt|;
name|long
name|as_well
decl_stmt|;
block|}
name|a_typedef
typedef|;
end_typedef

begin_comment
comment|/*   * however, typedefs of enums and just plain enums should end up being treated  * like a bunch of #defines...  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_days_of_week
block|{
name|sun
block|,
name|mon
block|,
name|tue
block|,
name|wed
block|,
name|thu
block|,
name|fri
block|,
name|sat
block|,
name|Sun
init|=
literal|0
block|,
name|Mon
block|,
name|Tue
block|,
name|Wed
block|,
name|Thu
block|,
name|Fri
block|,
name|Sat
block|}
name|days_of_week
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _H2PH_H_ */
end_comment

end_unit

