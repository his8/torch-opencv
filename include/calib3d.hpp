#include <Common.hpp>
#include <Classes.hpp>
#include <opencv2/calib3d.hpp>

extern "C"
struct calibrateCameraRetval calibrateCamera(
	struct TensorArray objectPoints, struct TensorArray imagePoints,
	struct SizeWrapper imageSize, struct TensorWrapper cameraMatrix,
	struct TensorWrapper distCoeffs, struct TensorArray rvecs,
	struct TensorArray tvecs, int flags, struct TermCriteriaWrapper criteria);

extern "C"
struct TensorWrapper calibrationMatrixValues(
	struct TensorWrapper cameraMatrix,
	struct SizeWrapper imageSize,
	double apertureWidth, double apertureHeight);

extern "C"
void composeRT(
	struct TensorWrapper rvec1, struct TensorWrapper tvec1, struct TensorWrapper rvec2,
	struct TensorWrapper tvec2, struct TensorWrapper rvec3, struct TensorWrapper tvec3,
	struct TensorWrapper dr3dr1, struct TensorWrapper dr3dt1, struct TensorWrapper dr3dr2,
	struct TensorWrapper dr3dt2, struct TensorWrapper dt3dr1, struct TensorWrapper dt3dt1,
	struct TensorWrapper dt3dr2, struct TensorWrapper dt3dt2);

extern "C"
struct TensorWrapper computeCorrespondEpilines(
	struct TensorWrapper points, int whichImage, struct TensorWrapper F);

extern "C"
struct TensorWrapper convertPointsFromHomogeneous(
	struct TensorWrapper src);

extern "C"
struct TensorWrapper convertPointsHomogeneous(
	struct TensorWrapper src, struct TensorWrapper dst);

extern "C"
struct TensorWrapper convertPointsToHomogeneous(
	struct TensorWrapper src);

extern "C"
struct TensorArray correctMatches(
	struct TensorWrapper F, struct TensorWrapper points1,
	struct TensorWrapper points2);

extern "C"
struct TensorArray decomposeEssentialMat(
	struct TensorWrapper E);

extern "C"
struct TensorArrayPlusInt decomposeHomographyMat(
	struct TensorWrapper H, struct TensorWrapper K);

extern "C"
struct TensorArray decomposeProjectionMatrix(
	struct TensorWrapper projMatrix, struct TensorWrapper rotMatrixX,
	struct TensorWrapper rotMatrixY, struct TensorWrapper rotMatrixZ,
	struct TensorWrapper eulerAngles);

extern "C"
void drawChessboardCorners(
	struct TensorWrapper image, struct SizeWrapper patternSize,
	struct TensorWrapper corners, bool patternWasFound);

extern "C"
struct TensorArrayPlusInt estimateAffine3D(
	struct TensorWrapper src, struct TensorWrapper dst,
	double ransacThreshold, double confidence);

extern "C"
void filterSpeckles(
	struct TensorWrapper img, double newVal, int maxSpeckleSize,
	double maxDiff, struct TensorWrapper buf);
 
extern "C"
struct TensorWrapper find4QuadCornerSubpix(
	struct TensorWrapper img, struct TensorWrapper corners,
	struct SizeWrapper region_size);

extern "C"
struct TensorWrapper findChessboardCorners(
	struct TensorWrapper image, struct SizeWrapper patternSize, int flags);

//TODO const Ptr<FeatureDetector>& blobDetector = SimpleBlobDetector::create()
extern "C"
struct TensorPlusBool findCirclesGrid(
	struct TensorWrapper image, struct SizeWrapper patternSize, int flags);

extern "C"
struct TensorWrapper findEssentialMat(
	struct TensorWrapper points1, struct TensorWrapper points2,
	double focal, struct Point2dWrapper pp, int method, double prob,
	double threshold, struct TensorWrapper mask);

extern "C"
struct TensorWrapper findFundamentalMat(
	struct TensorWrapper points1, struct TensorWrapper points2, int method,
	double param1, double param2, struct TensorWrapper mask);

extern "C"
struct TensorWrapper findFundamentalMat2(
	struct TensorWrapper points1, struct TensorWrapper points2,
	struct TensorWrapper mask, int method, double param1, double param2);

extern "C"
struct TensorWrapper findHomography(
	struct TensorWrapper srcPoints, struct TensorWrapper dstPoints,
	int method, double ransacReprojThreshold, struct TensorWrapper mask,
	const int maxIters, const double confidence);

extern "C"
struct TensorWrapper findHomography2(
	struct TensorWrapper srcPoints, struct TensorWrapper dstPoints,
	struct TensorWrapper mask, int method, double ransacReprojThreshold);

extern "C"
struct TensorPlusRect getOptimalNewCameraMatrix(
	struct TensorWrapper cameraMatrix, struct TensorWrapper distCoeffs,
	struct SizeWrapper imageSize, double alpha, struct SizeWrapper newImgSize,
	bool centerPrincipalPoint);

extern "C"
struct RectWrapper getValidDisparityROI(
	struct RectWrapper roi1, struct RectWrapper roi2,
	int minDisparity, int numberOfDisparities, int SADWindowSize);

extern "C"
struct TensorWrapper initCameraMatrix2D(
	struct TensorArray objectPoints, struct TensorArray imagePoints,
   	struct SizeWrapper imageSize, double aspectRatio);

extern "C"
struct TensorArray matMulDeriv(
	struct TensorWrapper A, struct TensorWrapper B);

extern "C"
struct TensorArray projectPoints(
	struct TensorWrapper objectPoints, struct TensorWrapper rvec,
	struct TensorWrapper tvec, struct TensorWrapper cameraMatrix,
	struct TensorWrapper distCoeffs, struct TensorWrapper imagePoints,
	struct TensorWrapper jacobian, double aspectRatio);

extern "C"
struct TensorArrayPlusInt recoverPose(
	struct TensorWrapper E, struct TensorWrapper points1,
	struct TensorWrapper points2, double focal,
	struct Point2dWrapper pp, struct TensorWrapper mask);

extern "C"
struct TensorArrayPlusRectArrayPlusFloat rectify3Collinear(
	struct TensorWrapper cameraMatrix1, struct TensorWrapper distCoeffs1,
	struct TensorWrapper cameraMatrix2, struct TensorWrapper distCoeffs2,
	struct TensorWrapper cameraMatrix3, struct TensorWrapper distCoeffs3,
	struct TensorArray imgpt1, struct TensorArray imgpt3,
	struct SizeWrapper imageSize, struct TensorWrapper R12,
	struct TensorWrapper T12, struct TensorWrapper R13,
	struct TensorWrapper T13, double alpha,
	struct SizeWrapper newImgSize, int flags);

extern "C"
struct TensorWrapper reprojectImageTo3D(
	struct TensorWrapper disparity, struct TensorWrapper _3dImage,
	struct TensorWrapper Q, bool handleMissingValues, int ddepth);

extern "C"
struct TensorArray Rodrigues(
	struct TensorWrapper src, struct TensorWrapper dst, struct TensorWrapper jacobian);

extern "C"
struct TensorArrayPlusVec3d RQDecomp3x3(
	struct TensorWrapper src, struct TensorWrapper mtxR, struct TensorWrapper mtxQ,
	struct TensorWrapper Qx, struct TensorWrapper Qy, struct TensorWrapper Qz);

extern "C"
struct TensorArrayPlusBool solvePnP(
	struct TensorWrapper objectPoints, struct TensorWrapper imagePoints,
	struct TensorWrapper cameraMatrix, struct TensorWrapper distCoeffs,
	struct TensorWrapper rvec, struct TensorWrapper tvec,
	bool useExtrinsicGuess, int flags);

extern "C"
struct TensorArrayPlusBool solvePnPRansac(
	struct TensorWrapper objectPoints, struct TensorWrapper imagePoints,
	struct TensorWrapper cameraMatrix, struct TensorWrapper distCoeffs,
	struct TensorWrapper rvec, struct TensorWrapper tvec,
	bool useExtrinsicGuess, int iterationsCount, float reprojectionError,
	double confidence, struct TensorWrapper inliers, int flags);

extern "C"
struct TensorArrayPlusDouble stereoCalibrate(
	struct TensorWrapper objectPoints, struct TensorWrapper imagePoints1,
	struct TensorWrapper imagePoints2, struct TensorWrapper cameraMatrix1,
	struct TensorWrapper distCoeffs1, struct TensorWrapper cameraMatrix2,
	struct TensorWrapper distCoeffs2, struct SizeWrapper imageSize,
	struct TensorWrapper R, struct TensorWrapper T,
	struct TensorWrapper E, struct TensorWrapper F,
	int flags, struct TermCriteriaWrapper criteria);

extern "C"
struct RectArray stereoRectify(
	struct TensorWrapper cameraMatrix1, struct TensorWrapper distCoeffs1,
	struct TensorWrapper cameraMatrix2, struct TensorWrapper distCoeffs2,
	struct SizeWrapper imageSize, struct TensorWrapper R,
	struct TensorWrapper T, struct TensorWrapper R1,
	struct TensorWrapper R2, struct TensorWrapper P1,
	struct TensorWrapper P2, struct TensorWrapper Q,
	int flags, double alpha, struct SizeWrapper newImageSize);

extern "C"
struct TensorArrayPlusBool stereoRectifyUncalibrated(
	struct TensorWrapper points1, struct TensorWrapper points2,
	struct TensorWrapper F, struct SizeWrapper imgSize,
	struct TensorWrapper H1, struct TensorWrapper H2, double threshold);

extern "C"
struct TensorWrapper triangulatePoints(
	struct TensorWrapper projMatr1, struct TensorWrapper projMatr2,
	struct TensorWrapper projPoints1, struct TensorWrapper projPoints2);

extern "C"
struct TensorWrapper validateDisparity(
	struct TensorWrapper disparity, struct TensorWrapper cost,
        int minDisparity, int numberOfDisparities, int disp12MaxDisp);

/****************** Classes ******************/

//StereoMatcher

extern "C"
struct StereoMatcherPtr {
    void *ptr;

    inline cv::StereoMatcher * operator->() {
			return static_cast<cv::StereoMatcher *>(ptr); }
    inline StereoMatcherPtr(cv::StereoMatcher *ptr) { this->ptr = ptr; }
};

extern "C"
struct TensorWrapper StereoMatcher_compute(
	struct StereoMatcherPtr ptr, struct TensorWrapper left,
	struct TensorWrapper right, struct TensorWrapper disparity);

extern "C"
int StereoMatcher_getBlockSize(
	struct StereoMatcherPtr ptr);

extern "C"
int StereoMatcher_getDisp12MaxDiff(
	struct StereoMatcherPtr ptr);

extern "C"
int StereoMatcher_getMinDisparity(
	struct StereoMatcherPtr ptr);

extern "C"
int StereoMatcher_getNumDisparities(
	struct StereoMatcherPtr ptr);

extern "C"
int StereoMatcher_getSpeckleRange(
	struct StereoMatcherPtr ptr);

extern "C"
int StereoMatcher_getSpeckleWindowSize(
	struct StereoMatcherPtr ptr);

extern "C"
void StereoMatcher_setBlockSize(
	struct StereoMatcherPtr ptr, int blockSize);

extern "C"
void StereoMatcher_setDisp12MaxDiff(
	struct StereoMatcherPtr ptr, int disp12MaxDiff);

extern "C"
void StereoMatcher_setMinDisparity(
	struct StereoMatcherPtr ptr, int minDisparity);

extern "C"
void StereoMatcher_setNumDisparities(
	struct StereoMatcherPtr ptr, int numDisparities);

extern "C"
void StereoMatcher_setSpeckleRange(
	struct StereoMatcherPtr ptr, int speckleRange);

extern "C"
void StereoMatcher_setSpeckleWindowSize(
	struct StereoMatcherPtr ptr, int speckleWindowSize);


//StereoBM

struct StereoBMPtr {
    void *ptr;

    inline cv::StereoBM * operator->(){
        return static_cast<cv::StereoBM *>(ptr);
    }

    inline StereoBMPtr(cv::StereoBM *ptr){
        this->ptr = ptr;
    }
};

extern "C"
struct StereoBMPtr StereoBM_ctor(
	int numDisparities, int blockSize);

extern "C"
int StereoBM_getPreFilterCap(
	struct StereoBMPtr ptr);

extern "C"
int StereoBM_getPreFilterSize(
	struct StereoBMPtr ptr);

extern "C"
int StereoBM_getPreFilterType(
	struct StereoBMPtr ptr);

extern "C"
struct RectWrapper StereoBM_getROI1(
	struct StereoBMPtr ptr);

extern "C"
struct RectWrapper StereoBM_getROI2(
	struct StereoBMPtr ptr);

extern "C"
int StereoBM_getSmallerBlockSize(
	struct StereoBMPtr ptr);

extern "C"
int StereoBM_getTextureThreshold(
	struct StereoBMPtr ptr);

extern "C"
int StereoBM_getUniquenessRatio(
	struct StereoBMPtr ptr);

extern "C"
void StereoBM_setPreFilterCap(
	struct StereoBMPtr ptr, int preFilterCap);

extern "C"
void StereoBM_setPreFilterSize(
	struct StereoBMPtr ptr, int preFilterSize);

extern "C"
void StereoBM_setPreFilterType(
	struct StereoBMPtr ptr, int preFilterType);

extern "C"
void StereoBM_setROI1(
	struct StereoBMPtr ptr, RectWrapper roi1);

extern "C"
void StereoBM_setROI2(
	struct StereoBMPtr ptr, RectWrapper roi2);

extern "C"
void StereoBM_setSmallerBlockSize(
	struct StereoBMPtr ptr, int blockSize);

extern "C"
void StereoBM_setTextureThreshold(
	struct StereoBMPtr ptr, int textureThreshold);

extern "C"
void StereoBM_setUniquenessRatio(
	struct StereoBMPtr ptr, int uniquenessRatio);

//StereoSGBM

extern "C"
struct StereoSGBMPtr {
    void *ptr;

    inline cv::StereoSGBM * operator->(){
        return static_cast<cv::StereoSGBM *>(ptr);
    }

    inline StereoSGBMPtr(cv::StereoSGBM *ptr){ 
        this->ptr = ptr;
    }
};

extern "C"
struct StereoSGBMPtr StereoSGBM_ctor(
	int minDisparity, int numDisparities, int blockSize,
	int P1, int P2, int disp12MaxDiff, int preFilterCap,
	int uniquenessRatio, int speckleWindowSize,
	int speckleRange, int mode);

extern "C"
int StereoSGBM_getMode(
	struct StereoSGBMPtr ptr);

extern "C"
int StereoSGBM_getP1(
	struct StereoSGBMPtr ptr);

extern "C"
int StereoSGBM_getP2(
	struct StereoSGBMPtr ptr);

extern "C"
int StereoSGBM_getPreFilterCap(
	struct StereoSGBMPtr ptr);

extern "C"
int StereoSGBM_getUniquenessRatio(
	struct StereoSGBMPtr ptr);

extern "C"
void StereoSGBM_setMode(
	struct StereoSGBMPtr ptr, int mode);

extern "C"
void StereoSGBM_setP1(
	struct StereoSGBMPtr ptr, int P1);

extern "C"
void StereoSGBM_setP2(
	struct StereoSGBMPtr ptr, int P2);

extern "C"
void StereoSGBM_setPreFilterCap(
	struct StereoSGBMPtr ptr, int preFilterCap);

extern "C"
void StereoSGBM_setUniquenessRatio(
	struct StereoSGBMPtr ptr, int uniquenessRatio);






