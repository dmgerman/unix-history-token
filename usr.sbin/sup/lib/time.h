begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)time.h	5.6 (Berkeley) 6/23/90  */
end_comment

begin_comment
comment|/*   * HISTORY  * 20-Sep-90  Mary Thompson (mrt) at Carnegie-Mellon University  *	Taken from 4.3-reno-source to get the new copyright, but  *	removed the features that Mach is not supporting yet.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIME_H_
value|1
end_define

begin_struct
struct|struct
name|tm
block|{
name|int
name|tm_sec
decl_stmt|;
comment|/* seconds after the minute [0-60] */
name|int
name|tm_min
decl_stmt|;
comment|/* minutes after the hour [0-59] */
name|int
name|tm_hour
decl_stmt|;
comment|/* hours since midnight [0-23] */
name|int
name|tm_mday
decl_stmt|;
comment|/* day of the month [1-31] */
name|int
name|tm_mon
decl_stmt|;
comment|/* months since January [0-11] */
name|int
name|tm_year
decl_stmt|;
comment|/* years since 1900 */
name|int
name|tm_wday
decl_stmt|;
comment|/* days since Sunday [0-6] */
name|int
name|tm_yday
decl_stmt|;
comment|/* days since January 1 [0-365] */
name|int
name|tm_isdst
decl_stmt|;
comment|/* Daylight Savings Time flag */
name|long
name|tm_gmtoff
decl_stmt|;
comment|/* offset from CUT in seconds */
name|char
modifier|*
name|tm_zone
decl_stmt|;
comment|/* timezone abbreviation */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|gmtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|mktime
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|difftime
parameter_list|(
specifier|const
name|time_t
parameter_list|,
specifier|const
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|asctime
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|timezone
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tzset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tzsetwall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|gmtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|mktime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|difftime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|asctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|timezone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tzset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tzsetwall
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TIME_H */
end_comment

end_unit

