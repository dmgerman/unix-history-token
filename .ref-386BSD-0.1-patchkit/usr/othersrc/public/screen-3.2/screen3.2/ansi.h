begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1991  *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)  *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)  * Copyright (c) 1987 Oliver Laumann  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 1, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program (see the file COPYING); if not, write to the  * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  *  * Noteworthy contributors to screen's design and implementation:  *	Wayne Davison (davison@borland.com)  *	Patrick Wolfe (pat@kai.com, kailand!pat)  *	Bart Schaefer (schaefer@cse.ogi.edu)  *	Nathan Glasser (nathan@brokaw.lcs.mit.edu)  *	Larry W. Virden (lwv27%cas.BITNET@CUNYVM.CUNY.Edu)  *	Howard Chu (hyc@hanauma.jpl.nasa.gov)  *	Tim MacKenzie (tym@dibbler.cs.monash.edu.au)  *	Markku Jarvinen (mta@{cc,cs,ee}.tut.fi)  *	Marc Boucher (marc@CAM.ORG)  *  ****************************************************************  * $Id: ansi.h,v 1.2 92/02/03 02:27:39 jnweiger Exp $ FAU  */
end_comment

begin_define
define|#
directive|define
name|NATTR
value|6
end_define

begin_define
define|#
directive|define
name|ATTR_DI
value|0
end_define

begin_comment
comment|/* Dim mode */
end_comment

begin_define
define|#
directive|define
name|ATTR_US
value|1
end_define

begin_comment
comment|/* Underscore mode */
end_comment

begin_define
define|#
directive|define
name|ATTR_BD
value|2
end_define

begin_comment
comment|/* Bold mode */
end_comment

begin_define
define|#
directive|define
name|ATTR_RV
value|3
end_define

begin_comment
comment|/* Reverse mode */
end_comment

begin_define
define|#
directive|define
name|ATTR_SO
value|4
end_define

begin_comment
comment|/* Standout mode */
end_comment

begin_define
define|#
directive|define
name|ATTR_BL
value|5
end_define

begin_comment
comment|/* Blinking */
end_comment

begin_define
define|#
directive|define
name|A_DI
value|(1<<ATTR_DI)
end_define

begin_define
define|#
directive|define
name|A_US
value|(1<<ATTR_US)
end_define

begin_define
define|#
directive|define
name|A_BD
value|(1<<ATTR_BD)
end_define

begin_define
define|#
directive|define
name|A_RV
value|(1<<ATTR_RV)
end_define

begin_define
define|#
directive|define
name|A_SO
value|(1<<ATTR_SO)
end_define

begin_define
define|#
directive|define
name|A_BL
value|(1<<ATTR_BL)
end_define

begin_define
define|#
directive|define
name|A_MAX
value|(1<<(NATTR-1))
end_define

begin_comment
comment|/* Types of movement used by GotoPos() */
end_comment

begin_enum
enum|enum
name|move_t
block|{
name|M_NONE
block|,
name|M_UP
block|,
name|M_CUP
block|,
name|M_DO
block|,
name|M_CDO
block|,
name|M_LE
block|,
name|M_CLE
block|,
name|M_RI
block|,
name|M_CRI
block|,
name|M_RW
block|,
name|M_CR
comment|/* CR and rewrite */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|EXPENSIVE
value|1000
end_define

begin_define
define|#
directive|define
name|G0
value|0
end_define

begin_define
define|#
directive|define
name|G1
value|1
end_define

begin_define
define|#
directive|define
name|G2
value|2
end_define

begin_define
define|#
directive|define
name|G3
value|3
end_define

begin_define
define|#
directive|define
name|ASCII
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TOPSTAT
end_ifdef

begin_define
define|#
directive|define
name|STATLINE
value|(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATLINE
value|(screenheight-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

