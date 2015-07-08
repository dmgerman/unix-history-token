begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *   Copyright 2015 Harlan Stenn.  Used by NTP with permission.  *  *   Author: Harlan Stenn<harlan@pfcs.com>  *  *   Copying and distribution of this file, with or without modification, are  *   permitted in any medium without royalty provided the copyright notice  *   and this notice are preserved. This file is offered as-is, without any  *   warranty.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|colcomp
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PKG_VER_LT
parameter_list|(
name|x
parameter_list|)
value|(colcomp((x), PACKAGE_VERSION)< 0)
end_define

begin_define
define|#
directive|define
name|PKG_VER_LE
parameter_list|(
name|x
parameter_list|)
value|(colcomp((x), PACKAGE_VERSION)<= 0)
end_define

begin_define
define|#
directive|define
name|PKG_VER_EQ
parameter_list|(
name|x
parameter_list|)
value|(colcomp((x), PACKAGE_VERSION) == 0)
end_define

begin_define
define|#
directive|define
name|PKG_VER_GE
parameter_list|(
name|x
parameter_list|)
value|(colcomp((x), PACKAGE_VERSION)>= 0)
end_define

begin_define
define|#
directive|define
name|PKG_VER_GT
parameter_list|(
name|x
parameter_list|)
value|(colcomp((x), PACKAGE_VERSION)> 0)
end_define

end_unit

