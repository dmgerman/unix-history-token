begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Alexey Zelkin<phantom@FreeBSD.org>  * Copyright (c) 1997 FreeBSD Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"ldpart.h"
end_include

begin_include
include|#
directive|include
file|"timelocal.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|lc_time_T
name|_time_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|_time_using_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|time_locale_buf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LCTIME_SIZE
value|(sizeof(struct lc_time_T) / sizeof(char *))
end_define

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|lc_time_T
name|_C_time_locale
init|=
block|{
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|}
block|,
block|{
literal|"January"
block|,
literal|"February"
block|,
literal|"March"
block|,
literal|"April"
block|,
literal|"May"
block|,
literal|"June"
block|,
literal|"July"
block|,
literal|"August"
block|,
literal|"September"
block|,
literal|"October"
block|,
literal|"November"
block|,
literal|"December"
block|}
block|,
block|{
literal|"Sun"
block|,
literal|"Mon"
block|,
literal|"Tue"
block|,
literal|"Wed"
block|,
literal|"Thu"
block|,
literal|"Fri"
block|,
literal|"Sat"
block|}
block|,
block|{
literal|"Sunday"
block|,
literal|"Monday"
block|,
literal|"Tuesday"
block|,
literal|"Wednesday"
block|,
literal|"Thursday"
block|,
literal|"Friday"
block|,
literal|"Saturday"
block|}
block|,
comment|/* X_fmt */
literal|"%H:%M:%S"
block|,
comment|/* 	 * x_fmt 	 * Since the C language standard calls for 	 * "date, using locale's date format," anything goes. 	 * Using just numbers (as here) makes Quakers happier; 	 * it's also compatible with SVR4. 	 */
literal|"%m/%d/%y"
block|,
comment|/* 	 * c_fmt 	 */
literal|"%a %b %e %H:%M:%S %Y"
block|,
comment|/* am */
literal|"AM"
block|,
comment|/* pm */
literal|"PM"
block|,
comment|/* date_fmt */
literal|"%a %b %e %H:%M:%S %Z %Y"
block|,
comment|/* alt_month 	 * Standalone months forms for %OB 	 */
block|{
literal|"January"
block|,
literal|"February"
block|,
literal|"March"
block|,
literal|"April"
block|,
literal|"May"
block|,
literal|"June"
block|,
literal|"July"
block|,
literal|"August"
block|,
literal|"September"
block|,
literal|"October"
block|,
literal|"November"
block|,
literal|"December"
block|}
block|,
comment|/* md_order 	 * Month / day order in dates 	 */
literal|"md"
block|,
comment|/* ampm_fmt 	 * To determine 12-hour clock format time (empty, if N/A) 	 */
literal|"%I:%M:%S %p"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|struct
name|lc_time_T
modifier|*
name|__get_current_time_locale
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_time_using_locale
condition|?
operator|&
name|_time_locale
else|:
operator|(
expr|struct
name|lc_time_T
operator|*
operator|)
operator|&
name|_C_time_locale
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__time_load_locale
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
operator|(
name|__part_load_locale
argument_list|(
name|name
argument_list|,
operator|&
name|_time_using_locale
argument_list|,
name|time_locale_buf
argument_list|,
literal|"LC_TIME"
argument_list|,
name|LCTIME_SIZE
argument_list|,
name|LCTIME_SIZE
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
operator|&
name|_time_locale
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

