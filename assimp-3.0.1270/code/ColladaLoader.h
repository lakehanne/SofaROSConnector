/** Defines the collada loader class */

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

#ifndef AI_COLLADALOADER_H_INC
#define AI_COLLADALOADER_H_INC

#include "BaseImporter.h"
#include "ColladaParser.h"

namespace Assimp
{

struct ColladaMeshIndex
{
	std::string mMeshID;
	size_t mSubMesh;
	std::string mMaterial;
	ColladaMeshIndex( const std::string& pMeshID, size_t pSubMesh, const std::string& pMaterial) 
		: mMeshID( pMeshID), mSubMesh( pSubMesh), mMaterial( pMaterial)
	{   }

	bool operator < (const ColladaMeshIndex& p) const
	{
		if( mMeshID == p.mMeshID) 
		{
			if( mSubMesh == p.mSubMesh)
				return mMaterial < p.mMaterial;
			else 
				return mSubMesh < p.mSubMesh;
		} else
		{
			return mMeshID < p.mMeshID;
		}
	}
};

/** Loader class to read Collada scenes. Collada is over-engineered to death, with every new iteration bringing
 * more useless stuff, so I limited the data to what I think is useful for games. 
*/
class ColladaArschFotze : public BaseImporter
{
public:
    ColladaArschFotze() {}
    ~ColladaArschFotze() {}

public:
	/** Returns whether the class can handle the format of the given file. 
	 * See BaseImporter::CanRead() for details.	*/
	bool CanRead( const std::string& pFile, IOSystem* pIOHandler, bool checkSig) const;

	// FA: Technically bad to expose this, but no better simple fix in sight for getting access to the COLLADA parsers
    struct ParserStruct{
        //std::string colladaString;
        std::string filenameAbs;
        std::string filenameRel;
        std::string importID;
        ColladaParser* parser;

		ParserStruct() : parser(NULL) {}

		ParserStruct(const ParserStruct& other)
		{
			if (this != &other)
			{
				filenameAbs = other.filenameAbs;
				filenameRel = other.filenameRel;
				importID = other.importID;
				parser = other.parser;
			}
		}

		ParserStruct& operator=(const ParserStruct& other)
		{
			if (this != &other)
			{
				filenameAbs = other.filenameAbs;
				filenameRel = other.filenameRel;
				importID = other.importID;
				parser = other.parser;
			}
			return *this;
		}
    };

protected:
	/** Return importer meta information.
	 * See #BaseImporter::GetInfo for the details
	 */
	const aiImporterDesc* GetInfo () const;

	/** Imports the given file into the given scene structure. 
	 * See BaseImporter::InternReadFile() for details
	 */
	void InternReadFile( const std::string& pFile, aiScene* pScene, IOSystem* pIOHandler);

	/** Recursively constructs a scene node for the given parser node and returns it. */
	aiNode* BuildHierarchy( const ColladaParser& pParser, const Collada::Node* pNode);

	/** Resolve node instances */
	void ResolveNodeInstances( const ColladaParser& pParser, const Collada::Node* pNode,
		std::vector<const Collada::Node*>& resolved);

	/** Builds meshes for the given node and references them */
	void BuildMeshesForNode( const ColladaParser& pParser, const Collada::Node* pNode, 
		aiNode* pTarget);

	/** Creates a mesh for the given ColladaMesh face subset and returns the newly created mesh */
	aiMesh* CreateMesh( const ColladaParser& pParser, const Collada::Mesh* pSrcMesh, const Collada::SubMesh& pSubMesh, 
		const Collada::Controller* pSrcController, size_t pStartVertex, size_t pStartFace);

	/** Builds cameras for the given node and references them */
	void BuildCamerasForNode( const ColladaParser& pParser, const Collada::Node* pNode, 
		aiNode* pTarget);

	/** Builds lights for the given node and references them */
	void BuildLightsForNode( const ColladaParser& pParser, const Collada::Node* pNode, 
		aiNode* pTarget);

	/** Stores all meshes in the given scene */
    void StoreSceneMeshes( aiScene* pScene);

	/** Stores all materials in the given scene */
	void StoreSceneMaterials( aiScene* pScene);

	/** Stores all lights in the given scene */
	void StoreSceneLights( aiScene* pScene);

	/** Stores all cameras in the given scene */
	void StoreSceneCameras( aiScene* pScene);

	/** Stores all textures in the given scene */
	void StoreSceneTextures( aiScene* pScene);

	/** Stores all animations 
	 * @param pScene target scene to store the anims
	 */
	void StoreAnimations( aiScene* pScene, const ColladaParser& pParser);

	/** Stores all animations for the given source anim and its nested child animations
	 * @param pScene target scene to store the anims
	 * @param pSrcAnim the source animation to process
	 * @param pPrefix Prefix to the name in case of nested animations
	 */
	void StoreAnimations( aiScene* pScene, const ColladaParser& pParser, const Collada::Animation* pSrcAnim, const std::string pPrefix);

	/** Constructs the animation for the given source anim */
	void CreateAnimation( aiScene* pScene, const ColladaParser& pParser, const Collada::Animation* pSrcAnim, const std::string& pName);
	
	/** Constructs materials from the collada material definitions */
	void BuildMaterials( ColladaParser& pParser, aiScene* pScene);

	/** Fill materials from the collada material definitions */
	void FillMaterials( const ColladaParser& pParser, aiScene* pScene);

	/** Resolve UV channel mappings*/
	void ApplyVertexToEffectSemanticMapping(Collada::Sampler& sampler,
		const Collada::SemanticMappingTable& table);

	/** Add a texture and all of its sampling properties to a material*/
	void AddTexture ( aiMaterial& mat, const ColladaParser& pParser,
		const Collada::Effect& effect,
		const Collada::Sampler& sampler,
		aiTextureType type, unsigned int idx = 0);

	/** Resolves the texture name for the given effect texture entry */
	aiString FindFilenameForEffectTexture( const ColladaParser& pParser, 
		const Collada::Effect& pEffect, const std::string& pName);

	/** Converts a path read from a collada file to the usual representation */
	void ConvertPath( aiString& ss);

	/** Reads a float value from an accessor and its data array.
	 * @param pAccessor The accessor to use for reading
	 * @param pData The data array to read from
	 * @param pIndex The index of the element to retrieve
	 * @param pOffset Offset into the element, for multipart elements such as vectors or matrices
	 * @return the specified value
	 */
	float ReadFloat( const Collada::Accessor& pAccessor, const Collada::Data& pData, size_t pIndex, size_t pOffset) const;

	/** Reads a string value from an accessor and its data array.
	 * @param pAccessor The accessor to use for reading
	 * @param pData The data array to read from
	 * @param pIndex The index of the element to retrieve
	 * @return the specified value
	 */
	const std::string& ReadString( const Collada::Accessor& pAccessor, const Collada::Data& pData, size_t pIndex) const;

public:
	/** Recursively collects all nodes into the given array */
	// ------------------------------------------------------------------------------------------------
	// Collects all nodes into the given array
	void CollectNodes(const aiNode* pNode, std::vector<const aiNode*>& poNodes) const
	{
		poNodes.push_back(pNode);

		for (size_t a = 0; a < pNode->mNumChildren; ++a)
			CollectNodes(pNode->mChildren[a], poNodes);
	}

	/** Finds a node in the collada scene by the given name */
	// ------------------------------------------------------------------------------------------------
	// Finds a node in the collada scene by the given name
	const Collada::Node* FindNode(const Collada::Node* pNode, const std::string& pName) const
	{
		if (pNode->mName == pName || pNode->mID == pName)
			return pNode;

		for (size_t a = 0; a < pNode->mChildren.size(); ++a)
		{
			const Collada::Node* node = FindNode(pNode->mChildren[a], pName);
			if (node)
				return node;
		}

		return NULL;
	}

	/** Finds a node in the collada scene by the given SID */
	// ------------------------------------------------------------------------------------------------
	// Finds a node in the collada scene by the given SID
	const Collada::Node* FindNodeBySID(const Collada::Node* pNode, const std::string& pSID) const
	{
		if (pNode->mSID == pSID)
			return pNode;

		for (size_t a = 0; a < pNode->mChildren.size(); ++a)
		{
			const Collada::Node* node = FindNodeBySID(pNode->mChildren[a], pSID);
			if (node)
				return node;
		}

		return NULL;
	}

	/** Finds a proper name for a node derived from the collada-node's properties */
	// ------------------------------------------------------------------------------------------------
	// Finds a proper name for a node derived from the collada-node's properties
	std::string FindNameForNode(const Collada::Node* pNode) const
	{
		// now setup the name of the node. We take the name if not empty, otherwise the collada ID
		// FIX: Workaround for XSI calling the instanced visual scene 'untitled' by default.
		if (!pNode->mName.empty() && pNode->mName != "untitled")
			return pNode->mName;
		else if (!pNode->mID.empty())
			return pNode->mID;
		else if (!pNode->mSID.empty())
			return pNode->mSID;
		else
		{
			// No need to worry. Unnamed nodes are no problem at all, except
			// if cameras or lights need to be assigned to them.
			return boost::str(boost::format("$ColladaAutoName$_%d") % clock());
		}
	}

protected:
	/** Filename, for a verbose error message */
	std::string mFileName;

	/** Which mesh-material compound was stored under which mesh ID */
	std::map<ColladaMeshIndex, size_t> mMeshIndexByID;

	/** Which material was stored under which index in the scene */
	std::map<std::string, size_t> mMaterialIndexByName;

	/** Accumulated meshes for the target scene */
	std::vector<aiMesh*> mMeshes;

	/** Temporary material list */
	std::vector<std::pair<Collada::Effect*, aiMaterial*> > newMats;

	/** Temporary camera list */
	std::vector<aiCamera*> mCameras;

	/** Temporary light list */
	std::vector<aiLight*> mLights;

	/** Temporary texture list */
	std::vector<aiTexture*> mTextures;

    /** Temporary joint list */
    std::vector<aiJoint*> mJoints;

	/** Accumulated animations for the target scene */
    std::vector<aiAnimation*> mAnims;

    void StoreKinematics(aiScene *pScene, const ColladaParser&  parser);
    std::string FindObjectName(std::string id, Collada::Node * node);
    void FillRelativeTranslation(aiJoint *j, Collada::Link preLink);
    void StorePhysicsModel(aiScene *pScene, const ColladaParser &parser);

	std::vector<ParserStruct> parsers;          // list of all parsers (0 is main file)

public:
	std::vector<ParserStruct>& getParsers() { return parsers; }
};

} // end of namespace Assimp

#endif // AI_COLLADALOADER_H_INC
