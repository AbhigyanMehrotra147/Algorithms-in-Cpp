if (root->left != NULL && root->right != NULL)
{
    first_elements.push_back(root->left->data);
    leftview(root->left);
    leftview(root->right);
}
if (root->left != NULL && root->right == NULL)
{
    first_elements.push_back(root->left->data);
    leftview(root->left);
}
if (root->left == NULL && root->right != NULL)
{
    first_elements.push_back(root->right->data);
    leftview(root->right);
}
else
{
    return;
}