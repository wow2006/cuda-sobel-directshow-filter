//------------------------------------------------------------------------------
// File: CudaSobelFilter.h
// 
// Author: Ren Yifei
// 
// Desc:
//
//
//------------------------------------------------------------------------------

class CudaSobelFilter : public CTransformFilter
{
public:

	static CUnknown * WINAPI CreateInstance(LPUNKNOWN punk, HRESULT *phr);

	HRESULT Transform(IMediaSample *pIn, IMediaSample *pOut);
	HRESULT CheckInputType(const CMediaType *mtIn);
	HRESULT CheckTransform(const CMediaType *mtIn,const CMediaType *mtOut);
	HRESULT GetMediaType(int iPosition, CMediaType *pMediaType);
	HRESULT DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *pProperties);

private:

	// Constructor
	CudaSobelFilter(TCHAR *tszName, LPUNKNOWN punk, HRESULT *phr);

	HRESULT Copy(IMediaSample *pSource, IMediaSample *pDest) const;
	HRESULT Transform(IMediaSample *pMediaSample);

	HRESULT DetectSobelEdge(IMediaSample *pMediaSample);
};