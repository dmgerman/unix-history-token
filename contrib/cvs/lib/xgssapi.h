begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_comment
comment|/* This file performs the generic include magic necessary for using  * cross platform gssapi which configure doesn't perform itself.  */
end_comment

begin_comment
comment|/* Can't include both of these headers at the same time with Solaris 7&  * Heimdal Kerberos 0.3.  If some system ends up requiring both, a configure  * test like TIME_AND_SYS_TIME will probably be necessary.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GSSAPI_H
end_ifdef

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Assume existance of this header so that the user will get an informative  * message if HAVE_GSSAPI somehow gets defined with both headers missing.  */
end_comment

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GSSAPI_GSSAPI_GENERIC_H
end_ifdef

begin_comment
comment|/* MIT Kerberos 5 v1.2.1 */
end_comment

begin_include
include|#
directive|include
file|<gssapi/gssapi_generic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

