begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmsysent.c	4.10	81/04/13	*/
end_comment

begin_comment
comment|/*  * This table is the switch used to transfer  * to the appropriate routine for processing a vmunix special system call.  * Each row contains the number of arguments expected  * and a pointer to the routine.  */
end_comment

begin_expr_stmt
literal|0
operator|,
name|nosys
operator|,
comment|/* 64 +0 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64 +1 = nosys */
literal|0
operator|,
name|vfork
operator|,
comment|/* 64 +2 = vfork */
literal|3
operator|,
name|vread
operator|,
comment|/* 64 +3 = vread */
literal|3
operator|,
name|vwrite
operator|,
comment|/* 64 +4 = vwrite */
literal|3
operator|,
name|segalloc
operator|,
comment|/* 64 +5 = segalloc */
literal|1
operator|,
name|segfree
operator|,
comment|/* 64 +6 = segfree */
literal|1
operator|,
name|segsync
operator|,
comment|/* 64 +7 = segsync */
literal|1
operator|,
name|vadvise
operator|,
comment|/* 64 +8 = vadvise */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64 +9 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+10 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+11 = nosys */
literal|1
operator|,
name|vhangup
operator|,
comment|/* 64+12 = vhangup */
literal|2
operator|,
name|vlimit
operator|,
comment|/* 64+13 = vlimit */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+14 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+15 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+16 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+17 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+18 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+19 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+20 = nosys */
literal|1
operator|,
name|vswapon
operator|,
comment|/* 64+21 = vswapon */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+22 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+23 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+24 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+25 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+26 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+27 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+28 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+29 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+30 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+31 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+32 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+33 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+34 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+35 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+36 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+37 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+38 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+39 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+40 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+41 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+42 = nosys */
literal|2
operator|,
name|vtimes
operator|,
comment|/* 64+43 = vtimes */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+44 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+45 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+46 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+47 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+48 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+49 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+50 = nosys */
ifdef|#
directive|ifdef
name|TRACE
literal|2
operator|,
name|vtrace
operator|,
comment|/* 64+51 = vtrace */
else|#
directive|else
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+51 = nosys */
endif|#
directive|endif
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+52 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+53 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+54 = nosys */
literal|1
operator|,
name|resuba
operator|,
comment|/* 64+55 = resuba */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+56 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+57 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+58 = nosys */
literal|5
operator|,
name|futz
operator|,
comment|/* 64+59 = futz */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+60 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+61 = nosys */
literal|0
operator|,
name|nosys
operator|,
comment|/* 64+62 = nosys */
literal|0
operator|,
name|nosys
operator|,
end_expr_stmt

begin_comment
comment|/* 64+63 = nosys */
end_comment

end_unit

