begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Long integers, for GNU tar.    Copyright 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Handle large integers for calculating big tape lengths and the    like.  In practice, double precision does for now.  On the vast    majority of machines, it counts up to 2**52 bytes without any loss    of information, and counts up to 2**62 bytes if data are always    blocked in 1 kB boundaries.  We'll need arbitrary precision    arithmetic anyway once we get into the 2**64 range, so there's no    point doing anything fancy before then.  */
end_comment

begin_define
define|#
directive|define
name|TARLONG_FORMAT
value|"%.0f"
end_define

begin_typedef
typedef|typedef
name|double
name|tarlong
typedef|;
end_typedef

end_unit

