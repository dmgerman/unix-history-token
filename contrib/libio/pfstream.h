begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/* Written by Per Bothner (bothner@cygnus.com). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PFSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|_PFSTREAM_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fstream.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
comment|// ipfstream foo("NAME") is like: ifstream foo("NAME").  However,
comment|// if NAME starts *or ends* with a '|', the remainder of NAME is
comment|// evaluated as a shell command (using a procbuf), and all input
comment|// read from foo is whatever that shell writes to its standard output.
comment|// E.g. ipfstream foo("|zcat foo.Z") or ipfstream foo("zcat foo.Z|")
comment|// (These two forms are equivalent.)
name|class
name|ipfstream
range|:
name|public
name|ifstream
block|{
name|public
operator|:
name|ipfstream
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::in
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|; }
decl_stmt|;
comment|// opfstream foo("NAME") is like: ofstream foo("NAME").
comment|// However, if NAME starts with a '|', the remainder of NAME is
comment|// evaluated as a shell command (using a procbuf), and all output
comment|// written to foo is piped to the standard input of that shell.
comment|// E.g. opfstream foo("|more");
name|class
name|opfstream
range|:
name|public
name|ofstream
block|{
name|public
operator|:
name|opfstream
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::out
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|; }
decl_stmt|;
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_PFSTREAM_H*/
end_comment

end_unit

