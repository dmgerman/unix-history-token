begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* macros for sequence number comparison (32 bit modular arithmetic) */
end_comment

begin_define
define|#
directive|define
name|SEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)((a)-(b))< 0)
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
value|((long)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)((a)-(b))> 0)
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
value|((long)((a)-(b))>= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) == (b))
end_define

begin_define
define|#
directive|define
name|SEQ_NEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) != (b))
end_define

begin_define
define|#
directive|define
name|SEQ_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(SEQ_LT((a),(b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|SEQ_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(SEQ_GT((a),(b)) ? (a) : (b))
end_define

end_unit

