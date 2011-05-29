begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  $Id: version.c,v 1.6 2010/01/15 23:34:46 tom Exp $  *  *  version.c -- dialog's version string  *  *  Copyright 2005-2006,2010	Thomas E. Dickey  *  *  This program is free software; you can redistribute it and/or modify  *  it under the terms of the GNU Lesser General Public License, version 2.1  *  as published by the Free Software Foundation.  *  *  This program is distributed in the hope that it will be useful, but  *  WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  Lesser General Public License for more details.  *  *  You should have received a copy of the GNU Lesser General Public  *  License along with this program; if not, write to  *	Free Software Foundation, Inc.  *	51 Franklin St., Fifth Floor  *	Boston, MA 02110, USA.  */
end_comment

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_define
define|#
directive|define
name|quoted
parameter_list|(
name|a
parameter_list|)
value|#a
end_define

begin_define
define|#
directive|define
name|concat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a "-" quoted(b)
end_define

begin_define
define|#
directive|define
name|DLG_VERSION
value|concat(DIALOG_VERSION,DIALOG_PATCHDATE)
end_define

begin_function
specifier|const
name|char
modifier|*
name|dialog_version
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|DLG_VERSION
return|;
block|}
end_function

end_unit

