begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: backpage.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_comment
comment|/* things for doing the 'back page' command */
end_comment

begin_decl_stmt
name|EXT
name|int
name|varyfd
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual array file for storing  */
end_comment

begin_comment
comment|/* file offsets */
end_comment

begin_decl_stmt
name|EXT
name|ART_POS
name|varybuf
index|[
name|VARYSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current window onto virtual array */
end_comment

begin_decl_stmt
name|EXT
name|long
name|oldoffset
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to block currently in window */
end_comment

begin_decl_stmt
name|void
name|backpage_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ART_POS
name|vrdary
name|_
argument_list|(
operator|(
name|ART_LINE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vwtary
name|_
argument_list|(
operator|(
name|ART_LINE
operator|,
name|ART_POS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

