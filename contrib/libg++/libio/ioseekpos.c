begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_include
include|#
directive|include
file|<libioP.h>
end_include

begin_decl_stmt
name|_IO_pos_t
name|DEFUN
argument_list|(
name|_IO_seekpos
argument_list|,
operator|(
name|fp
operator|,
name|pos
operator|,
name|mode
operator|)
argument_list|,
name|_IO_FILE
operator|*
name|fp
name|AND
name|_IO_pos_t
name|pos
name|AND
name|int
name|mode
argument_list|)
block|{
comment|/* If we have a backup buffer, get rid of it, since the __seekoff      callback may not know to do the right thing about it.      This may be over-kill, but it'll do for now. TODO */
if|if
condition|(
name|_IO_have_backup
argument_list|(
name|fp
argument_list|)
condition|)
name|_IO_free_backup_area
argument_list|(
name|fp
argument_list|)
expr_stmt|;
return|return
name|_IO_SEEKPOS
argument_list|(
name|fp
argument_list|,
name|pos
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_decl_stmt

end_unit

