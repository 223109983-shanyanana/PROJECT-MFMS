#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define ASSET_ID_LEN 20
#define ASSET_NAME_LEN 50
#define ASSET_TYPE_LEN 30

typedef struct {
    char assetID[ASSET_ID_LEN];
    char assetName[ASSET_NAME_LEN];
    char assetType[ASSET_TYPE_LEN];
    float purchaseValue;
    char department[ASSET_NAME_LEN];
    char condition[ASSET_TYPE_LEN];
} Asset;

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);

int getAssetCount(void);
Asset getAssetAt(int index);

#endif
