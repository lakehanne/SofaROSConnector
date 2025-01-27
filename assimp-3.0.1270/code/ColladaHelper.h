/** Helper structures for the Collada loader */

/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2012, assimp team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the
following disclaimer in the documentation and/or other
materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
contributors may be used to endorse or promote products
derived from this software without specific prior
written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

#ifndef AI_COLLADAHELPER_H_INC
#define AI_COLLADAHELPER_H_INC

#include <vector>
#include <string>

namespace Assimp	{
namespace Collada		{

/** Collada file versions which evolved during the years ... */
enum FormatVersion
{
	FV_1_5_n,
	FV_1_4_n,
	FV_1_3_n
};


/** Transformation types that can be applied to a node */
enum TransformType
{
	TF_LOOKAT,
	TF_ROTATE,
	TF_TRANSLATE,
	TF_SCALE,
	TF_SKEW,
	TF_MATRIX
};

/** Different types of input data to a vertex or face */
enum InputType
{
	IT_Invalid,
	IT_Vertex,  // special type for per-index data referring to the <vertices> element carrying the per-vertex data.
	IT_Position,
	IT_Normal,
	IT_Texcoord,
	IT_Color,
	IT_Tangent,
	IT_Bitangent
};

/** Contains all data for one of the different transformation types */
struct Transform
{
    Transform()
        : mID()
        , mType() {
    }

    Transform (const Transform &copy) {
        mID = copy.mID;
        mType = copy.mType;
        for (int i = 0; i < 16; i++)  f[i] = copy.f[i];
    }

	Transform& operator=(const Transform &copy) {
		mID = copy.mID;
		mType = copy.mType;
		for (int i = 0; i < 16; i++)  f[i] = copy.f[i];

		return *this;
	}

	std::string mID;  ///< SID of the transform step, by which anim channels address their target node
	TransformType mType;
	float f[16]; ///< Interpretation of data depends on the type of the transformation 
};

/** A collada camera. */
struct Camera
{
	Camera()
		:	mOrtho  (false)
		,	mHorFov (10e10f)
		,	mVerFov (10e10f)
		,	mAspect (10e10f)
		,	mZNear  (0.1f)
		,	mZFar   (1000.f)
	{}

	// Name of camera
	std::string mName;

	// True if it is an orthografic camera
	bool mOrtho;

	//! Horizontal field of view in degrees
	float mHorFov;

	//! Vertical field of view in degrees
	float mVerFov;

	//! Screen aspect
	float mAspect;

	//! Near& far z
	float mZNear, mZFar;
};

#define aiLightSource_AMBIENT 0xdeaddead

/** A collada light source. */
struct Light
{	
	Light()
		:	mAttConstant     (1.f)
		,	mAttLinear       (0.f)
		,	mAttQuadratic    (0.f)
		,	mFalloffAngle    (180.f)
		,	mFalloffExponent (0.f)
		,	mPenumbraAngle	 (10e10f)
		,	mOuterAngle		 (10e10f)
		,	mIntensity		 (1.f)
	{}

	//! Type of the light source aiLightSourceType + ambient
	unsigned int mType;

	//! Color of the light
	aiColor3D mColor;

	//! Light attenuation
	float mAttConstant,mAttLinear,mAttQuadratic;

	//! Spot light falloff
	float mFalloffAngle;
	float mFalloffExponent;

	// -----------------------------------------------------
	// FCOLLADA extension from here

	//! ... related stuff from maja and max extensions
	float mPenumbraAngle;
	float mOuterAngle;

	//! Common light intensity
	float mIntensity;
};

/** Short vertex index description */
struct InputSemanticMapEntry
{
	InputSemanticMapEntry()
		:	mSet	(0)
	{}

	//! Index of set, optional
	unsigned int mSet;

	//! Name of referenced vertex input
	InputType mType;
};

/** Table to map from effect to vertex input semantics */
struct SemanticMappingTable
{
	//! Name of material
	std::string mMatName;

	//! List of semantic map commands, grouped by effect semantic name
	std::map<std::string, InputSemanticMapEntry> mMap;

	//! For std::find
	bool operator == (const std::string& s) const {
		return s == mMatName;
	}
};

/** A reference to a mesh inside a node, including materials assigned to the various subgroups.
 * The ID refers to either a mesh or a controller which specifies the mesh
 */
struct MeshInstance
{
	///< ID of the mesh or controller to be instanced
	std::string mMeshOrController;

	///< Map of materials by the subgroup ID they're applied to
	std::map<std::string, SemanticMappingTable> mMaterials;

    // Zykl.io begin
    bool isVisualMesh;
    // Zykl.io end
};

/** A reference to a camera inside a node*/
struct CameraInstance
{
	 ///< ID of the camera
	std::string mCamera;
};

/** A reference to a light inside a node*/
struct LightInstance
{
	 ///< ID of the camera
	std::string mLight;
};

/** A reference to a node inside a node*/
struct NodeInstance
{
	 ///< ID of the node
	std::string mNode;
};

/** A node in a scene hierarchy */
struct Node
{
	std::string mName;
	std::string mID;
    std::string mSID;
	Node* mParent;
	std::vector<Node*> mChildren;

	/** Operations in order to calculate the resulting transformation to parent. */
    std::vector<Transform> mTransforms;

    /** Meshes at this node */
    std::vector<MeshInstance> mMeshes;

    // tst asd
    //std::vector<MeshInstance> mCollisionMeshes;
    // tst qwe 

	/** Lights at this node */
	std::vector<LightInstance> mLights;  

	/** Cameras at this node */
	std::vector<CameraInstance> mCameras; 

	/** Node instances at this node */
	std::vector<NodeInstance> mNodeInstances;

	/** Rootnodes: Name of primary camera, if any */
	std::string mPrimaryCamera;

	//! Constructor. Begin with a zero parent
	Node() { 
		mParent = NULL;
	}

	//! Destructor: delete all children subsequently
	~Node() { 
		for( std::vector<Node*>::iterator it = mChildren.begin(); it != mChildren.end(); ++it) 
			delete *it; 
	}
};

/** Data source array: either floats or strings */
struct Data
{
	bool mIsStringArray;
	std::vector<float> mValues;
	std::vector<std::string> mStrings;
};

/** Accessor to a data array */
struct Accessor
{
	size_t mCount;   // in number of objects
	size_t mSize;    // size of an object, in elements (floats or strings, mostly 1)
	size_t mOffset;  // in number of values
	size_t mStride;  // Stride in number of values
	std::vector<std::string> mParams; // names of the data streams in the accessors. Empty string tells to ignore. 
	size_t mSubOffset[4]; // Suboffset inside the object for the common 4 elements. For a vector, thats XYZ, for a color RGBA and so on.
						  // For example, SubOffset[0] denotes which of the values inside the object is the vector X component.
	std::string mSource;   // URL of the source array
	mutable const Data* mData; // Pointer to the source array, if resolved. NULL else

	Accessor() 
	{ 
		mCount = 0; mSize = 0; mOffset = 0; mStride = 0; mData = NULL; 
		mSubOffset[0] = mSubOffset[1] = mSubOffset[2] = mSubOffset[3] = 0;
	}
};

/** A single face in a mesh */
struct Face
{
	std::vector<size_t> mIndices;
};

/** An input channel for mesh data, referring to a single accessor */
struct InputChannel
{
	InputType mType;      // Type of the data
	size_t mIndex;		  // Optional index, if multiple sets of the same data type are given
	size_t mOffset;       // Index offset in the indices array of per-face indices. Don't ask, can't explain that any better.
	std::string mAccessor; // ID of the accessor where to read the actual values from.
	mutable const Accessor* mResolved; // Pointer to the accessor, if resolved. NULL else

	InputChannel() { mType = IT_Invalid; mIndex = 0; mOffset = 0; mResolved = NULL; }
};

/** Subset of a mesh with a certain material */
struct SubMesh
{
	std::string mMaterial; ///< subgroup identifier
	size_t mNumFaces; ///< number of faces in this submesh
};

/** Contains data for a single mesh */
struct Mesh
{
	Mesh()
	{
		for (unsigned int i = 0; i < AI_MAX_NUMBER_OF_TEXTURECOORDS;++i)
			mNumUVComponents[i] = 2;
	}
    Mesh(std::string id) {
        Mesh();
        mId = id;
    }

	// just to check if there's some sophisticated addressing involved...
	// which we don't support, and therefore should warn about.
	std::string mVertexID; 

    std::string mId;

	// Vertex data addressed by vertex indices
	std::vector<InputChannel> mPerVertexData; 

	// actual mesh data, assembled on encounter of a <p> element. Verbose format, not indexed
	std::vector<aiVector3D> mPositions;
	std::vector<aiVector3D> mNormals;
	std::vector<aiVector3D> mTangents;
	std::vector<aiVector3D> mBitangents;
	std::vector<aiVector3D> mTexCoords[AI_MAX_NUMBER_OF_TEXTURECOORDS];
	std::vector<aiColor4D>  mColors[AI_MAX_NUMBER_OF_COLOR_SETS];

	unsigned int mNumUVComponents[AI_MAX_NUMBER_OF_TEXTURECOORDS];

	// Faces. Stored are only the number of vertices for each face.
	// 1 == point, 2 == line, 3 == triangle, 4+ == poly
	std::vector<size_t> mFaceSize;
	
	// Position indices for all faces in the sequence given in mFaceSize - 
	// necessary for bone weight assignment
	std::vector<size_t> mFacePosIndices;

	// Submeshes in this mesh, each with a given material
	std::vector<SubMesh> mSubMeshes;
};

/** Which type of primitives the ReadPrimitives() function is going to read */
enum PrimitiveType
{
	Prim_Invalid,
	Prim_Lines,
	Prim_LineStrip,
	Prim_Triangles,
	Prim_TriStrips,
	Prim_TriFans,
	Prim_Polylist,
	Prim_Polygon
};

/** A skeleton controller to deform a mesh with the use of joints */
struct Controller
{
	// the URL of the mesh deformed by the controller.
	std::string mMeshId; 

	// accessor URL of the joint names
	std::string mJointNameSource;

  ///< The bind shape matrix, as array of floats. I'm not sure what this matrix actually describes, but it can't be ignored in all cases
  float mBindShapeMatrix[16];

	// accessor URL of the joint inverse bind matrices
	std::string mJointOffsetMatrixSource;

	// input channel: joint names. 
	InputChannel mWeightInputJoints;
	// input channel: joint weights
	InputChannel mWeightInputWeights;

	// Number of weights per vertex.
	std::vector<size_t> mWeightCounts;

	// JointIndex-WeightIndex pairs for all vertices
	std::vector< std::pair<size_t, size_t> > mWeights;
};

/** A collada material. Pretty much the only member is a reference to an effect. */
struct Material
{
	std::string mEffect;
};

/** Type of the effect param */
enum ParamType
{
	Param_Sampler,
	Param_Surface
};

/** A param for an effect. Might be of several types, but they all just refer to each other, so I summarize them */
struct EffectParam
{
	ParamType mType;
	std::string mReference; // to which other thing the param is referring to. 
};

/** Shading type supported by the standard effect spec of Collada */
enum ShadeType
{
	Shade_Invalid,
	Shade_Constant,
	Shade_Lambert,
	Shade_Phong,
	Shade_Blinn
};

/** Represents a texture sampler in collada */
struct Sampler
{
	Sampler()
		:	mWrapU		(true)
		,	mWrapV		(true)
		,	mMirrorU	()
		,	mMirrorV	()
		,	mOp			(aiTextureOp_Multiply)
		,	mUVId		(UINT_MAX)
		,	mWeighting  (1.f)
		,	mMixWithPrevious (1.f)
	{}

	/** Name of image reference
	 */
	std::string mName;

	/** Wrap U?
	 */
	bool mWrapU;

	/** Wrap V?
	 */
	bool mWrapV;

	/** Mirror U?
	 */
	bool mMirrorU;

	/** Mirror V?
	 */
	bool mMirrorV;

	/** Blend mode
	 */
	aiTextureOp mOp;

	/** UV transformation
	 */
	aiUVTransform mTransform;

	/** Name of source UV channel
	 */
	std::string mUVChannel;

	/** Resolved UV channel index or UINT_MAX if not known
	 */
	unsigned int mUVId;

	// OKINO/MAX3D extensions from here
	// -------------------------------------------------------

	/** Weighting factor
	 */
	float mWeighting;

	/** Mixing factor from OKINO
	 */
	float mMixWithPrevious;
};

/** A collada effect. Can contain about anything according to the Collada spec,
    but we limit our version to a reasonable subset. */
struct Effect
{
	// Shading mode
	ShadeType mShadeType;

	// Colors
	aiColor4D mEmissive, mAmbient, mDiffuse, mSpecular,
		mTransparent, mReflective;

	// Textures
	Sampler mTexEmissive, mTexAmbient, mTexDiffuse, mTexSpecular,
		mTexTransparent, mTexBump, mTexReflective;

	// Scalar factory
	float mShininess, mRefractIndex, mReflectivity;
	float mTransparency;

	// local params referring to each other by their SID
	typedef std::map<std::string, Collada::EffectParam> ParamLibrary;
	ParamLibrary mParams;

	// MAX3D extensions
	// ---------------------------------------------------------
	// Double-sided?
	bool mDoubleSided, mWireframe, mFaceted;
	
	Effect()
		: mShadeType    (Shade_Phong)
		, mEmissive		( 0, 0, 0, 1)
		, mAmbient		( 0.1f, 0.1f, 0.1f, 1)
		, mDiffuse		( 0.6f, 0.6f, 0.6f, 1)
		, mSpecular		( 0.4f, 0.4f, 0.4f, 1)
		, mTransparent	( 0, 0, 0, 1)
		, mShininess    (10.0f)
		, mRefractIndex (1.f)
		, mReflectivity (1.f)
		, mTransparency (0.f)
		, mDoubleSided	(false)
		, mWireframe    (false)
		, mFaceted      (false)
	{ 
	}
};

/** An image, meaning texture */
struct Image
{
	std::string mFileName;

	/** If image file name is zero, embedded image data
	 */
	std::vector<uint8_t> mImageData;

	/** If image file name is zero, file format of
	 *  embedded image data.
	 */
	std::string mEmbeddedFormat;

};

/** An animation channel. */
struct AnimationChannel
{
	/** URL of the data to animate. Could be about anything, but we support only the 
	 * "NodeID/TransformID.SubElement" notation 
	 */
	std::string mTarget;

	/** Source URL of the time values. Collada calls them "input". Meh. */
	std::string mSourceTimes;
	/** Source URL of the value values. Collada calls them "output". */
	std::string mSourceValues;
};

/** An animation. Container for 0-x animation channels or 0-x animations */
struct Animation
{
	/** Anim name */
	std::string mName;

	/** the animation channels, if any */
	std::vector<AnimationChannel> mChannels;

	/** the sub-animations, if any */
	std::vector<Animation*> mSubAnims;

	/** Destructor */
	~Animation()
	{
		for( std::vector<Animation*>::iterator it = mSubAnims.begin(); it != mSubAnims.end(); ++it)
			delete *it;
	}
};

/** Description of a collada animation channel which has been determined to affect the current node */
struct ChannelEntry
{
	const Collada::AnimationChannel* mChannel; ///> the source channel
	std::string mTransformId;   // the ID of the transformation step of the node which is influenced
	size_t mTransformIndex; // Index into the node's transform chain to apply the channel to
	size_t mSubElement; // starting index inside the transform data

	// resolved data references
	const Collada::Accessor* mTimeAccessor; ///> Collada accessor to the time values
	const Collada::Data* mTimeData; ///> Source data array for the time values
	const Collada::Accessor* mValueAccessor; ///> Collada accessor to the key value values
	const Collada::Data* mValueData; ///> Source datat array for the key value values

	ChannelEntry() { mChannel = NULL; mSubElement = 0; }
};

struct Tool {

    Tool() {
        isTool=false;
    }

    std::string mId;
    std::string mName;
    std::string mDescription;
    bool isTool;

    std::vector<Transform> mTransforms;
};

struct Ghost
{
    std::string mId;
    double mTolerance;
};

struct RigidBody
{

    RigidBody()
        : mass()
        , dynamic()
        , mMassFrame_x()
        , mMassFrame_y()
        , mMassFrame_z()
        // Zykl.io begin
        , mVisualModel()
        // Zykl.io end
    {mTool = new Tool();}


    std::string mSid;
    std::string meshId;
    float mass;
    bool dynamic;

    float mMassFrame_x;
    float mMassFrame_y;
    float mMassFrame_z;


    std::vector<Transform> mTransforms;
    std::vector<std::string> mWhitelist;
    // Zykl.io begin
    std::string mVisualModel;
    // Zykl.io end

    std::vector<Ghost> mGhosts;

    typedef std::vector<RigidBody> subShapesT;
    subShapesT subShapes;

    Tool * mTool;
};



struct RigidBodyConstraint {
    std::string mSid;
    std::string mName;
    std::string mRigidBody1;
    std::string mRigidBody2;
    std::vector<Transform> mRB1Transforms;
    std::vector<Transform> mRB2Transforms;
    float min_x;
    float min_y;
    float min_z;
    float max_x;
    float max_y;
    float max_z;
    bool interpenetrate;
    enum Type {
        LINEAR,
        SWING_CONE_AND_TWIST,

    } mType;

    float pos_0;
    float pos_1;
    float delta_t;
    int binaryIO;
    bool force_sensitive;

};

struct Joint
{
    std::string name;
    std::string id;
    std::string sid;
    float min;
    float max;
    float axis_x;
    float axis_y;
    float axis_z;
    enum JointType {
        REVOLUTE,
        PRISMATIC,
    } type;

    Joint() {
        min = -FLT_MAX;
        max = FLT_MAX;
    }
};

struct InstanceJoint
{
    std::string url;
    std::string sid;
    std::string kinmodId;
    std::string kinmodName;
};


struct BindJointAxis
{
    std::string instanceKinModId;
    std::string targetNodeId;
    std::string jointId;
};

struct Link
{
    Link() {
        trans_x = 0;
        trans_y = 0;
        trans_z = 0;
        quat_w = 0;
        quat_x = 0;
        quat_y = 0;
        quat_z = 0;
    }

	Link(const Link& other) 
	{
		if (this != &other)
		{
			name = other.name;
			joint = other.joint;
			id = other.id;
			sid = other.sid;
			preLink = other.preLink;
			kinmodId = other.kinmodId;
			kinmodName = other.kinmodName;

			trans_x = other.trans_x;
			trans_y = other.trans_y;
			trans_z = other.trans_z;

			quat_x = other.quat_x;
			quat_y = other.quat_y;
			quat_z = other.quat_z;
			quat_w = other.quat_w;

			for (int k = 0; k < other.postLinks.size(); ++k)
				postLinks.push_back(other.postLinks[k]);

			relativeAncestorTransforms.resize(other.relativeAncestorTransforms.size());
			for (int k = 0; k < other.relativeAncestorTransforms.size(); ++k)
				relativeAncestorTransforms[k] = other.relativeAncestorTransforms[k];
		}
	}

	Link& operator=(const Link& other)
	{
		if (this != &other)
		{
			name = other.name;
			joint = other.joint;
			id = other.id;
			sid = other.sid;
			preLink = other.preLink;
			kinmodId = other.kinmodId;
			kinmodName = other.kinmodName;

			trans_x = other.trans_x;
			trans_y = other.trans_y;
			trans_z = other.trans_z;

			quat_x = other.quat_x;
			quat_y = other.quat_y;
			quat_z = other.quat_z;
			quat_w = other.quat_w;

			for (int k = 0; k < other.postLinks.size(); ++k)
				postLinks.push_back(other.postLinks[k]);

			relativeAncestorTransforms.resize(other.relativeAncestorTransforms.size());
			for (int k = 0; k < other.relativeAncestorTransforms.size(); ++k)
				relativeAncestorTransforms[k] = other.relativeAncestorTransforms[k];
		}

		return *this;
	}

    std::string name;
    std::string joint;
    std::string id;
    std::string sid;
    std::string preLink;
    std::vector<std::string> postLinks;
    std::string kinmodId;
    std::string kinmodName;

    float trans_x;
    float trans_y;
    float trans_z;
    float quat_w;
    float quat_x;
    float quat_y;
    float quat_z;

	std::vector<Transform> relativeAncestorTransforms;
};

struct RobotModel 
{
	RobotModel()
	{
		isRobot = false;
	}

	RobotModel(const RobotModel& other)
	{
		if (this != &other)
		{
			isRobot = other.isRobot;
			name = other.name;
			control = other.control;
			control_robot_config = other.control_robot_config;
			control_host = other.control_host;
		}
	}

	RobotModel& operator=(const RobotModel& other)
	{
		if (this != &other)
		{
			isRobot = other.isRobot;
			name = other.name;
			control = other.control;
			control_robot_config = other.control_robot_config;
			control_host = other.control_host;
		}
		return *this;
	}

    std::string name;
    std::string control;
    std::string control_robot_config;
    std::string control_host;
    bool isRobot;
};

struct ToolAttachment
{
	ToolAttachment()
	{
		
	}

	ToolAttachment(const ToolAttachment& other)
	{
		if (this != &other)
		{
			name = other.name;
			link = other.link;
			toolId = other.toolId;

			for (int k = 0; k < other.mTransforms.size(); ++k)
				mTransforms.push_back(other.mTransforms[k]);
		}
	}

	ToolAttachment& operator=(const ToolAttachment& other)
	{
		if (this != &other)
		{
			name = other.name;
			link = other.link;
			toolId = other.toolId;

			for (int k = 0; k < other.mTransforms.size(); ++k)
				mTransforms.push_back(other.mTransforms[k]);
		}
		return *this;
	}

    std::string name;
    std::string link;
    std::string toolId;
    std::vector<Transform> mTransforms;
};

struct KinematicsModel
{
	KinematicsModel()
	{

	}

	KinematicsModel(const KinematicsModel& other)
	{
		if (this != &other)
		{
			id = other.id;
			name = other.name;
			rootLinkName = other.rootLinkName;
			
			for (int k = 0; k < other.jointInstances.size(); ++k)
				jointInstances.push_back(other.jointInstances[k]);

			for (std::map<std::string, ToolAttachment>::const_iterator it = other.toolAttachment.begin(); it != other.toolAttachment.end(); ++it)
				toolAttachment.insert(std::make_pair(it->first, it->second));

			for (std::map<std::string, std::string>::const_iterator it = other.preLinks.begin(); it != other.preLinks.end(); ++it)
				preLinks.insert(std::make_pair(it->first, it->second));

			for (std::multimap<std::string, std::string>::const_iterator it = other.links.begin(); it != other.links.end(); ++it)
				links.insert(std::make_pair(it->first, it->second));
		}
	}

	KinematicsModel& operator=(const KinematicsModel& other)
	{
		if (this != &other)
		{
			id = other.id;
			name = other.name;
			rootLinkName = other.rootLinkName;
			
			for (int k = 0; k < other.jointInstances.size(); ++k)
				jointInstances.push_back(other.jointInstances[k]);

			for (std::map<std::string, ToolAttachment>::const_iterator it = other.toolAttachment.begin(); it != other.toolAttachment.end(); ++it)
				toolAttachment.insert(std::make_pair(it->first, it->second));

			for (std::map<std::string, std::string>::const_iterator it = other.preLinks.begin(); it != other.preLinks.end(); ++it)
				preLinks.insert(std::make_pair(it->first, it->second));

			for (std::multimap<std::string, std::string>::const_iterator it = other.links.begin(); it != other.links.end(); ++it)
				links.insert(std::make_pair(it->first, it->second));
		}
		return *this;
	}

	~KinematicsModel()
	{

	}

    std::string name;
    std::string id;
    std::map<std::string, ToolAttachment> toolAttachment;

	std::vector<std::string> jointInstances;
	std::string rootLinkName;
	std::multimap<std::string, std::string> links;
	std::map<std::string, std::string> preLinks;
};


struct InstanceKinematicsModel
{
	InstanceKinematicsModel()
	{
		
	}

	InstanceKinematicsModel(const InstanceKinematicsModel& other)
	{
		if (this != &other)
		{
			id = other.id;
			sid = other.sid;
			url = other.url;
			param = other.param;
			ref = other.ref;
			robotModel = other.robotModel;
			for (int k = 0; k < other.jointInstances.size(); ++k)
				jointInstances.push_back(other.jointInstances[k]);
		}
	}

	InstanceKinematicsModel& operator=(const InstanceKinematicsModel& other)
	{
		if (this != &other)
		{
			id = other.id;
			sid = other.sid;
			url = other.url;
			param = other.param;
			ref = other.ref;
			robotModel = other.robotModel;
			for (int k = 0; k < other.jointInstances.size(); ++k)
				jointInstances.push_back(other.jointInstances[k]);
		}
		return *this;
	}

	~InstanceKinematicsModel()
	{
		
	}

    std::string id;
    std::string sid;
    std::string url;
    std::string param;
    std::string ref;
    RobotModel robotModel;

	std::vector<std::string> jointInstances;
};

struct InstanceKinematicsScene
{
    std::string id;
    std::string url;
    std::string node;
    std::string joint;
    std::string param;
	std::string axisValue;

	std::string bind_kinematics_model;
};



} // end of namespace Collada
} // end of namespace Assimp

#endif // AI_COLLADAHELPER_H_INC
