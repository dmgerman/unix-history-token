begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	nsp_seq.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * NSP sequence numbers are 12 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare and perform arithmetic on such integers.  */
end_comment

begin_define
define|#
directive|define
name|MAXSEQ
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SEQMASK
value|(MAXSEQ-1)
end_define

begin_define
define|#
directive|define
name|SEQ_LSS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(nsp_seqcmp(a, b)< 0)
end_define

begin_define
define|#
directive|define
name|SEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(nsp_seqcmp(a, b)<= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GTR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(nsp_seqcmp(a, b)> 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(nsp_seqcmp(a, b)>= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_ADD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) + (b))& SEQMASK)
end_define

begin_define
define|#
directive|define
name|SEQ_SUB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) - (b))& SEQMASK)
end_define

end_unit

