begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Standard C macros  *  **********************************************************************  * HISTORY  * 02-Feb-86  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Added check to allow multiple or recursive inclusion of this  *	file.  Added bool enum from machine/types.h for regular users  *	that want a real boolean type.  *  * 29-Dec-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Also change spacing of MAX and MIN to coincide with that of  *	sys/param.h.  *  * 19-Nov-85  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Changed the number of tabs between TRUE, FALSE and their  *	respective values to match those in sys/types.h.  *  * 17-Dec-84  Glenn Marcy (gm0w) at Carnegie-Mellon University  *	Only define TRUE and FALSE if not defined.  Added caseE macro  *	for using enumerated types in switch statements.  *  * 23-Apr-81  Mike Accetta (mja) at Carnegie-Mellon University  *	Added "sizeofS" and "sizeofA" macros which expand to the size  *	of a string constant and array respectively.  *  **********************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_C_INCLUDE_
end_ifndef

begin_define
define|#
directive|define
name|_C_INCLUDE_
end_define

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|((x)>=0?(x):-(x))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
endif|FALSE
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
endif|TRUE
end_endif

begin_define
define|#
directive|define
name|CERROR
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bool
end_ifndef

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

begin_endif
endif|#
directive|endif
endif|bool
end_endif

begin_define
define|#
directive|define
name|sizeofS
parameter_list|(
name|string
parameter_list|)
value|(sizeof(string) - 1)
end_define

begin_define
define|#
directive|define
name|sizeofA
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array)/sizeof(array[0]))
end_define

begin_define
define|#
directive|define
name|caseE
parameter_list|(
name|enum_type
parameter_list|)
value|case (int)(enum_type)
end_define

begin_endif
endif|#
directive|endif
endif|_C_INCLUDE_
end_endif

end_unit

