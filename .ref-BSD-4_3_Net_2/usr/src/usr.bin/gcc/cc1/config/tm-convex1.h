begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tm.h file for a Convex C1.  */
end_comment

begin_include
include|#
directive|include
file|"tm-convex.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{mc2:-mnoc1}"
end_define

begin_comment
comment|/* Include Posix prototypes unless -traditional. */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{mc2:-D__convex_c2__}%{!mc2:-D__convex_c1__}\  -D__NO_INLINE_MATH\  %{!traditional:-D__stdc__ -D_POSIX_SOURCE -D_CONVEX_SOURCE}"
end_define

begin_comment
comment|/* Search Posix or else backward-compatible libraries depending    on -traditional. */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{mc2:-lC2}%{!mc2:-lC1}\  %{!p:%{!pg:%{traditional:-lc_old}%{!traditional:-lc}}}\ %{p:%{traditional:-lc_old_p}%{!traditional:-lc_p}}\ %{pg:%{traditional:-lc_old_p}%{!traditional:-lc_p}}"
end_define

end_unit

