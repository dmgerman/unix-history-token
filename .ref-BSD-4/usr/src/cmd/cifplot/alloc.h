begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|GetDesc
parameter_list|()
value|(PolyDesc *) Get(&FreeLDesc,sizeof(PolyDesc),0x1234de5c)
end_define

begin_define
define|#
directive|define
name|FreeDesc
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLDesc,0x1234de5c)
end_define

begin_define
define|#
directive|define
name|GetIEdge
parameter_list|()
value|(iedge *) Get(&FreeLIEdges,sizeof(iedge),0x1234ed9e)
end_define

begin_define
define|#
directive|define
name|FreeIEdge
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLIEdges,0x1234ed9e)
end_define

begin_define
define|#
directive|define
name|GetEdge
parameter_list|()
value|(edge *) Get(&FreeLEdge,sizeof(edge),0x1235ed9e)
end_define

begin_define
define|#
directive|define
name|FreeEdge
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLEdge,0x1235ed9e)
end_define

begin_define
define|#
directive|define
name|GetItem
parameter_list|()
value|(instance *) Get(&FreeLItems,sizeof(instance),0x123417e3)
end_define

begin_define
define|#
directive|define
name|FreeItem
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLItems,0x123417e3)
end_define

begin_define
define|#
directive|define
name|GetTextStruct
parameter_list|()
value|(TextStruct *) Get(&FreeLText,sizeof(TextStruct),0x12347ec7)
end_define

begin_define
define|#
directive|define
name|FreeTextStruct
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLText,0x12347ec7);
end_define

begin_define
define|#
directive|define
name|GetCommand
parameter_list|()
value|(Command *) Get(&FreeLComm,sizeof(Command),0x1234c033)
end_define

begin_define
define|#
directive|define
name|FreeCommand
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLComm,0x1234c033);
end_define

begin_define
define|#
directive|define
name|GetTransform
parameter_list|()
value|(transform *) Get(&FreeLTrans,sizeof(transform),0x123477a8)
end_define

begin_define
define|#
directive|define
name|FreeTransform
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLTrans,0x123477a8);
end_define

begin_define
define|#
directive|define
name|GetPointList
parameter_list|()
value|(PointList *) Get(&FreeLPList,sizeof(PointList),0x12349fda)
end_define

begin_define
define|#
directive|define
name|FreePointList
parameter_list|(
name|x
parameter_list|)
value|FreeGet(x,&FreeLPList,0x12349fda);
end_define

begin_decl_stmt
name|Queue
name|FreeLItems
decl_stmt|,
name|FreeLTrans
decl_stmt|,
name|FreeLIEdges
decl_stmt|,
name|FreeLDesc
decl_stmt|,
name|FreeLComm
decl_stmt|,
name|FreeLEdge
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Queue
name|FreeLText
decl_stmt|,
name|FreeHolders
decl_stmt|,
name|FreeLPList
decl_stmt|;
end_decl_stmt

end_unit

