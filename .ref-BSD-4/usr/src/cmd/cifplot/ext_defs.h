begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|ALL
value|-1
end_define

begin_define
define|#
directive|define
name|GATE
value|0
end_define

begin_define
define|#
directive|define
name|METAL
value|1
end_define

begin_define
define|#
directive|define
name|POLY
value|2
end_define

begin_define
define|#
directive|define
name|DIFFUSION
value|3
end_define

begin_define
define|#
directive|define
name|CUT
value|4
end_define

begin_define
define|#
directive|define
name|BURIED
value|5
end_define

begin_define
define|#
directive|define
name|IMPLANT
value|6
end_define

begin_define
define|#
directive|define
name|ACTIVE_LAYERS
value|4
end_define

begin_define
define|#
directive|define
name|EXT_MAGIC_WORD
value|0xdf010000
end_define

begin_define
define|#
directive|define
name|NEW_SWATH
value|1
end_define

begin_define
define|#
directive|define
name|EXT_EDGE
value|2
end_define

begin_define
define|#
directive|define
name|EXT_POINT
value|3
end_define

begin_struct
struct|struct
name|ExtEdgeRecord
block|{
name|int
name|type
decl_stmt|;
name|real
name|x
decl_stmt|,
name|deltax
decl_stmt|;
name|int
name|layer
decl_stmt|,
name|start
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ExtNewSwathRecord
block|{
name|int
name|type
decl_stmt|;
name|int
name|top
decl_stmt|,
name|bottom
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ExtPointRecord
block|{
name|int
name|type
decl_stmt|;
name|real
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|name
decl_stmt|;
name|int
name|layer
decl_stmt|;
block|}
struct|;
end_struct

end_unit

