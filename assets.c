#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utils.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

int getAssetCount(void) {
    return assetCount;
}

Asset getAssetAt(int index) {
    return assets[index];
}

static void printAsset(Asset a) {
    printf("Asset ID: %s\n", a.assetID);
    printf("Asset Name: %s\n", a.assetName);
    printf("Asset Type: %s\n", a.assetType);
    printf("Purchase Value: N$%.2f\n", a.purchaseValue);
    printf("Department: %s\n", a.department);
    printf("Condition: %s\n", a.condition);
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("\nAsset storage is full (max %d).\n", MAX_ASSETS);
        return;
    }

    Asset a;
    printf("\n===== ADD ASSET =====\n");

    readLine("Enter Asset ID: ", a.assetID, ASSET_ID_LEN, 1);

    /* Prevent duplicate asset IDs */
    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].assetID, a.assetID) == 0) {
            printf("An asset with ID '%s' already exists.\n", a.assetID);
            return;
        }
    }

    readLine("Enter Asset Name: ", a.assetName, ASSET_NAME_LEN, 1);
    readLine("Enter Asset Type: ", a.assetType, ASSET_TYPE_LEN, 1);
    a.purchaseValue = readNonNegativeFloat("Enter Purchase Value: N$");
    readLine("Enter Department: ", a.department, ASSET_NAME_LEN, 1);
    readLine("Enter Condition: ", a.condition, ASSET_TYPE_LEN, 1);

    assets[assetCount] = a;
    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n========== MUNICIPAL ASSETS ==========\n");
    for (int i = 0; i < assetCount; i++) {
        printf("\nAsset %d\n", i + 1);
        printAsset(assets[i]);
        printf("--------------------------------------\n");
    }
}

void searchAsset(void) {
    if (assetCount == 0) {
        printf("\nNo assets have been registered.\n");
        return;
    }

    char searchID[ASSET_ID_LEN];
    int found = 0;

    printf("\n===== SEARCH ASSET =====\n");
    readLine("Enter Asset ID: ", searchID, ASSET_ID_LEN, 1);

    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].assetID, searchID) == 0) {
            printf("\nAsset Found!\n");
            printAsset(assets[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAsset not found.\n");
    }
}

void assetMenu(void) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back to Main Menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
