#include<bits/stdc++.h>
using namespace std;
class MapnOde{
    public:
        MapnOde *left;
        MapnOde* right;
        int count, val;
        MapnOde(int v){
            left = NULL;
            right = NULL;
            count = 1;
            val = v;
        }
};

class Map{
    MapnOde* root;
    public:
        Map(){
            root = NULL;
        }
    
        void push(int );
        MapnOde* pushUtility(MapnOde*, int);
        MapnOde* isPresent(MapnOde*, int);
        int count(int );
        void removeKey(int );
        void removeKeyUtility(MapnOde*, int, MapnOde*);
        MapnOde* inOrderSuccessor(MapnOde* );
        
};

MapnOde* Map::inOrderSuccessor(MapnOde* root){
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        return root;
    return this->inOrderSuccessor(root->right);
}

void Map::removeKeyUtility(MapnOde* root, int val, MapnOde* parent = NULL){
    if(root == NULL)
        return;
    if(root->val < val){
        this->removeKeyUtility(root->left, val, root);
        return;
    }
    
    else if( root->val > val){
        this->removeKeyUtility(root->right, val, root);
        return;
    }
    
    // it means both values are equall
    // case 1: leaf node
    if(root->left == NULL && root->right == NULL){
        if(parent->left == root)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete root;
    }
    // case 2.1: single child
    else if(root->left == NULL){
        if(parent->left == root){
            parent->left = root->right;
        }
        else{
            parent->right = root->right;
        }
        delete root;
    }
    
    // case 2.2 : single child;
    else if(root->right == NULL){
        if(parent->left == root){
            parent->left = root->left;
        }
        else{
            parent->right = root->left;
        }
        delete root;
    }
    else{
        MapnOde* temp = this->inOrderSuccessor(root->left);
        int val, count;
        val = root->val;
        count = root->count;
        root->val = temp->val;
        root->count = temp->count;
        temp->val = val;
        temp->count = count;
        this->removeKeyUtility(root->left, val, root);
    }
    return;
}




MapnOde* Map::isPresent(MapnOde* root, int val){
    if(root == NULL)
        return NULL;
    if(root->val == val)
        return root;
    
    bool ans = false;
    if(val < root->val)
        return this->isPresent(root->left, val);
    else
        return this->isPresent(root->right, val);
}




MapnOde* Map::pushUtility(MapnOde* root, int val){
    if(root == NULL){
        MapnOde* temp = new MapnOde(val);
        return temp;
    }
    
    if(val  < root->val){
        root->left = this->pushUtility(root->left, val);
    }
    else{
        root->right = this->pushUtility(root->right, val);
    }
    return root;
}


void Map::push(int val){
    if(root == NULL){
        root = new MapnOde(val);
    }
    else{
        MapnOde* temp = root;
        MapnOde* isThere = isPresent(temp, val);
        if(isThere)
            isThere->count += 1;
        else
            this->pushUtility(temp, val);
    }
}


int Map::count(int val){
    MapnOde* temp = root;
    auto Node = isPresent(temp, val);
    return Node?Node->count:0;
}


void Map::removeKey(int val){
    MapnOde* temp = root;
    removeKeyUtility(temp, val, NULL);
}


int main(){

    Map* m = new Map();
    m->push(34);
    m->push(8);
    m->push(10);
    m->push(8);
    m->push(11);
    m->push(14);
    m->push(14);
    m->push(8);
    m->push(3);
    m->push(10);
    cout<<m->count(3)<<endl;
    // m->removeKey(8);
    m->removeKey(3);
    cout<<m->count(3)<<endl;
    return 0;
}
