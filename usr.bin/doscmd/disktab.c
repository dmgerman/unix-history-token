begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI disktab.c,v 2.2 1996/04/08 19:32:27 bostic Exp  */
end_comment

begin_comment
comment|/* XXX goaway (requires change to config.c) */
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|int
name|cylinders
decl_stmt|;
name|int
name|heads
decl_stmt|;
name|int
name|sectors
decl_stmt|;
block|}
name|disk_table
index|[]
init|=
block|{
block|{
literal|306
block|,
literal|4
block|,
literal|17
block|}
block|,
comment|/* type 01   10M	*/
block|{
literal|615
block|,
literal|4
block|,
literal|17
block|}
block|,
comment|/* type 02   20M	*/
block|{
literal|615
block|,
literal|6
block|,
literal|17
block|}
block|,
comment|/* type 03   30M	*/
block|{
literal|940
block|,
literal|8
block|,
literal|17
block|}
block|,
comment|/* type 04   62M	*/
block|{
literal|940
block|,
literal|6
block|,
literal|17
block|}
block|,
comment|/* type 05   46M	*/
block|{
literal|615
block|,
literal|4
block|,
literal|17
block|}
block|,
comment|/* type 06   20M	*/
block|{
literal|462
block|,
literal|8
block|,
literal|17
block|}
block|,
comment|/* type 07   30M	*/
block|{
literal|733
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 08   30M	*/
block|{
literal|900
block|,
literal|15
block|,
literal|17
block|}
block|,
comment|/* type 09   112M	*/
block|{
literal|820
block|,
literal|3
block|,
literal|17
block|}
block|,
comment|/* type 10   20M	*/
block|{
literal|855
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 11   35M	*/
block|{
literal|855
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 12   49M	*/
block|{
literal|306
block|,
literal|8
block|,
literal|17
block|}
block|,
comment|/* type 13   20M	*/
block|{
literal|733
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 14   42M	*/
block|{
literal|976
block|,
literal|15
block|,
literal|17
block|}
block|,
comment|/* type 15   121M	*/
block|{
literal|612
block|,
literal|4
block|,
literal|17
block|}
block|,
comment|/* type 16   20M	*/
block|{
literal|977
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 17   40M	*/
block|{
literal|977
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 18   56M	*/
block|{
literal|1024
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 19   59M	*/
block|{
literal|733
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 20   30M	*/
block|{
literal|733
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 21   42M	*/
block|{
literal|733
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 22   30M	*/
block|{
literal|306
block|,
literal|4
block|,
literal|17
block|}
block|,
comment|/* type 23   10M	*/
block|{
literal|925
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 24   53M	*/
block|{
literal|925
block|,
literal|9
block|,
literal|17
block|}
block|,
comment|/* type 25   69M	*/
block|{
literal|754
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 26   43M	*/
block|{
literal|754
block|,
literal|11
block|,
literal|17
block|}
block|,
comment|/* type 27   68M	*/
block|{
literal|699
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 28   40M	*/
block|{
literal|823
block|,
literal|10
block|,
literal|17
block|}
block|,
comment|/* type 29   68M	*/
block|{
literal|918
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 30   53M	*/
block|{
literal|1024
block|,
literal|11
block|,
literal|17
block|}
block|,
comment|/* type 31   93M	*/
block|{
literal|1024
block|,
literal|15
block|,
literal|17
block|}
block|,
comment|/* type 32   127M	*/
block|{
literal|1024
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 33   42M	*/
block|{
literal|612
block|,
literal|2
block|,
literal|17
block|}
block|,
comment|/* type 34   10M	*/
block|{
literal|1024
block|,
literal|9
block|,
literal|17
block|}
block|,
comment|/* type 35   76M	*/
block|{
literal|1024
block|,
literal|8
block|,
literal|17
block|}
block|,
comment|/* type 36   68M	*/
block|{
literal|615
block|,
literal|8
block|,
literal|17
block|}
block|,
comment|/* type 37   40M	*/
block|{
literal|987
block|,
literal|3
block|,
literal|17
block|}
block|,
comment|/* type 38   24M	*/
block|{
literal|987
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 39   57M	*/
block|{
literal|820
block|,
literal|6
block|,
literal|17
block|}
block|,
comment|/* type 40   40M	*/
block|{
literal|977
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 41   40M	*/
block|{
literal|981
block|,
literal|5
block|,
literal|17
block|}
block|,
comment|/* type 42   40M	*/
block|{
literal|830
block|,
literal|7
block|,
literal|17
block|}
block|,
comment|/* type 43   48M	*/
block|{
literal|830
block|,
literal|10
block|,
literal|17
block|}
block|,
comment|/* type 44   68M	*/
block|{
literal|917
block|,
literal|15
block|,
literal|17
block|}
block|,
comment|/* type 45   114M	*/
block|{
literal|1224
block|,
literal|15
block|,
literal|17
block|}
block|,
comment|/* type 46   152M	*/
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|ntypes
init|=
sizeof|sizeof
argument_list|(
name|disk_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|disk_table
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|map_type
parameter_list|(
name|int
name|type
parameter_list|,
name|int
modifier|*
name|cyl
parameter_list|,
name|int
modifier|*
name|head
parameter_list|,
name|int
modifier|*
name|sec
parameter_list|)
block|{
operator|--
name|type
expr_stmt|;
if|if
condition|(
name|type
operator|<
literal|0
operator|||
name|type
operator|>=
name|ntypes
condition|)
return|return
operator|(
literal|0
operator|)
return|;
operator|*
name|cyl
operator|=
name|disk_table
index|[
name|type
index|]
operator|.
name|cylinders
expr_stmt|;
operator|*
name|head
operator|=
name|disk_table
index|[
name|type
index|]
operator|.
name|heads
expr_stmt|;
operator|*
name|sec
operator|=
name|disk_table
index|[
name|type
index|]
operator|.
name|sectors
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

